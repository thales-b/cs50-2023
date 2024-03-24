#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s IMAGE\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open image\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    bool opened = false;
    FILE *img = NULL;
    int count = 0;
    char filename[8];

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            if (!opened) {
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                if (img == NULL) {
                    perror("Error opening image file");
                    fclose(file);
                    return 1;
                }
                opened = true;
                count++;
            } else {
                fclose(img);
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                if (img == NULL) {
                    perror("Error opening image file");
                    fclose(file);
                    return 1;
                }
                count++;
            }
        }

        if (opened) {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    if (img != NULL) {
        fclose(img);
    }
    fclose(file);

    return 0;
}

