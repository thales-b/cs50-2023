// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    bool hasLower = false;
    bool hasUpper = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    for (int i = 0; password[i] != '\0'; i++)
    {
        char current = password[i];

        if (islower(current))
        {
            hasLower = true;
        }
        else if (isupper(current))
        {
            hasUpper = true;
        }
        else if (isdigit(current))
        {
            hasNumber = true;
        }
        else if (ispunct(current))
        {
            hasSymbol = true;
        }
    }

    return hasLower && hasUpper && hasNumber && hasSymbol;
}
