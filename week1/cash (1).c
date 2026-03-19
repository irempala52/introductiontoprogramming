#include <cs50.h>
#include <stdio.h>

//function prototypes
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    //Get input
    int cents = get_cents();
    //calculate coins
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;
    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;
    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;
    int pennies = calculate_pennies(cents);
    //print result
    printf("%i\n", quarters + dimes + nickels + pennies);
}
    int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
while (cents < 0);
return cents;
}
int calculate_quarters(int cents)
{
    return cents / 25;
}
int calculate_dimes(int cents)
{
    return cents / 10;
}
int calculate_nickels(int cents)
{
    return cents / 5;
}
int calculate_pennies(int cents)
{
    return cents;
}

