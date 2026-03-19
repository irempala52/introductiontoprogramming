#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

    long temp = number;
    int length = 0;

    while (temp > 0)
    {
        temp /=10;
        length++;
    }
    int sum_doubled = 0;
    int sum_rest = 0;

    int i = 0;
    long temp2 = number;

    while (temp2 > 0)
    {
        int digit = temp2 % 10;
        if (i % 2 ==1)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -=9 ;
            }
            sum_doubled += digit;
        }
        else
        {
            sum_rest += digit;
        }
        temp2 /= 10;
        i++;
    }
    int total = sum_doubled + sum_rest;
    if (total % 10 !=0)
    {
        printf("INVALID\n");
        return 0;
    }
    long start = number;
    while (start >=100)
    {
        start /= 10;
    }
    if (length == 15 && (start == 34|| start ==37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (start >= 51 && start <=55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (start / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
