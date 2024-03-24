#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    printf("Start size: ");
    scanf("%d", &start);
    while (start < 9)
    {
        printf("Start size: ");
        scanf("%d", &start);
    }
    int end;
    printf("End size: ");
    scanf("%d", &end);
    while (end < start)
    {
        printf("End size: ");
        scanf("%d", &end);
    }
    int n = 0;
    while (start < end)
    {
        start += (start / 3) - (start / 4);
        n++;
    }
    printf("Years: %d\n", n);
}

