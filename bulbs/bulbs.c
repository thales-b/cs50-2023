#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int length = strlen(message);

    for (int i = 0; i < length; i++)
    {
        int ascii = (int) message[i];
        for (int j = 7; j >= 0; j--)
        {
            int bit = (ascii >> j) & 1;
            print_bulb(bit);
        }
        printf("\n");
    }

    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        printf("⚫");  // Print black bulb emoji for 0
    }
    else if (bit == 1)
    {
        printf("🟡");  // Print yellow bulb emoji for 1
    }
}