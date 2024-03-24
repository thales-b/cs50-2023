#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number = get_long("Number: ");
    long n = number;
    int len = floor(log10(number)) + 1;
    int sum = 0;
    int digit = 0;
    int multiply = 0;
    for (int i = 0 ; i < len ; i++)
    {
        digit = (n % 10) % 10;
        printf("%d\n",digit);
        if (i % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            multiply = digit * 2;
            if (multiply >= 10)
            {
                sum += (multiply % 10) + (multiply / 10);
            }
            else
            {
                sum += multiply;
            }
        }
        n /= 10;
        printf("%ld\n",n);
    }
    string type = "INVALID\n";
    printf("%d\n", len);
    printf("%d\n", sum);
    if (sum % 10 != 0)
    {
        printf("%s", type);
        return 0;
    }
    int firstTwoDigits = number / (long) pow(10, len - 2);
    printf("%d\n", firstTwoDigits);
    if (len == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        type = "AMEX\n";
    }
    if (len == 16 && (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55))
    {
        type = "MASTERCARD\n";
    }
    if ((len == 13 || len == 16) && (number / (long)pow(10, len - 1) == 4))
    {
        type = "VISA\n";
    }
    printf("%s", type);
    return 0;
}
