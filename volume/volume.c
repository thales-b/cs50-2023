// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, 1, HEADER_SIZE, input);
    fwrite(header, 1, HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    int cap = 8;
    int16_t *samples = malloc(cap * sizeof(int16_t));
    if (samples == NULL)
    {
        exit(1);
    }
    int i = 0;
    int size = 0;
    while (fread(&samples[i], sizeof(int16_t), 1, input) == 1)
    {
        if (i == cap - 1)
        {
            cap *= 2;
            samples = realloc(samples, cap * sizeof(int16_t));
        }
        samples[i] = samples[i] * factor;
        i++;
        size++;
    }
    fwrite(samples, sizeof(int16_t), size, output);
    free(samples);


    // Close files
    fclose(input);
    fclose(output);
}
