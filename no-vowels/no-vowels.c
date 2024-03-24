// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

const char VOWELS[] = {'a', 'e', 'i', 'o', 'u'};
const int NUMBERS[] = {6, 3, 1, 0, 'u'};

char * replace(string word);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: %s [word]\n",argv[0]);
        return 1;
    }

    char* result = replace(argv[1]);
    printf("%s\n", result);
    printf("%s\n", result);
    return 0;
}

char * replace(string word) {
    static char result[100];
    strcpy(result, word);
    for (int i = 0; i < strlen(result); i++)
    {
        switch (result[i])
        {
            case 'a':
                result[i] = '6';
                break;
            case 'e':
                result[i] = '3';
                break;
            case 'i':
                result[i] = '1';
                break;
            case 'o':
                result[i] = '0';
                break;
            case 'u':
                break;
        }
    }
    return result;
}
