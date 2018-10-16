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

int main(void) {

    float change;
    int changeOwed;
    int coinsUsed = 0;

    // Get user input, validate that it's positive
    do {
        printf("Change: $");
        change = get_float();
    } while (change < 0.0);

    // Convert dollars (float) to cents (int). Needed to round to prevent float imprecision when truncated.
    change += 0.005f;
    changeOwed = change * 100;

    // Quarters
    while (changeOwed >= 25) {
        printf("used a quarter\n");
        changeOwed -= 25;
        coinsUsed++;
    }

    // Dimes
    while (changeOwed >= 10) {
        printf("used a dime\n");
        changeOwed -= 10;
        coinsUsed++;
    }

    // Nickels
    while (changeOwed >= 5) {
        printf("used a nickle\n");
        changeOwed -= 5;
        coinsUsed++;
    }

    // Pennies
    while (changeOwed >= 1) {
        printf("used a penny\n");
        changeOwed--;
        coinsUsed++;
    }

    // Print total coins used
    printf("Coins used: %i\n", coinsUsed);
}