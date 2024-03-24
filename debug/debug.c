// Become familiar wih C syntax
// Learn to debug buggy code

#include <stdio.h>
#include <cs50.h>


int main(void)
{
    char * name = get_string("What is your name? ");
    char * location = get_string("Where do you live? ");
    printf("Hello, %s, from %s!", name, location);
}

