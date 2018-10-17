/*
Greedy Cashier
--------------

Give the user change back in the fewest coins possible.

Task:
- Prompt and validate change
- Convert float to int
- Use largest coin(s) possible
- Print total coins used

**/

#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    float change;
    int change_owed;
    int coins_used = 0;

    // Get user input, validate that it's positive
    do
    {
        printf("Change: $");
        change = get_float();
    }
    while (change < 0.0);

    // Convert dollars (float) to cents (int). Needed to round to prevent float imprecision when truncated.
    change += 0.005f;
    change_owed = change * 100;

    // Quarters
    while (change_owed >= 25) {
        printf("used a quarter\n");
        change_owed -= 25;
        coins_used++;
    }

    // Dimes
    while (change_owed >= 10) {
        printf("used a dime\n");
        change_owed -= 10;
        coins_used++;
    }

    // Nickels
    while (change_owed >= 5) {
        printf("used a nickle\n");
        change_owed -= 5;
        coins_used++;
    }

    // Pennies
    while (change_owed >= 1) {
        printf("used a penny\n");
        change_owed--;
        coins_used++;
    }

    // Print total coins used
    printf("Coins used: %i\n", coins_used);
}