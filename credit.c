/*
Credit Card Verification
------------------------

Determine, via checksum, if a credit card number is valid and from what company
it's from (e.g. VISA, MasterCard). Functions apparently discouraged for this exercise.

Task:
- Prompt and validate CC number
- Analyze checksum of the number
    - Starting from second-to-last digit, multiply every digit by 2
    - Add those products' digits together (not the numbers, the digits! So instead of n + 14, it should be n + 1 + 4)
    - Add the sum to the sum of digits that were not multiplied by 2 together
    - If the last digit is 0, the checksum is valid
- Display company ID and checksum validity
    - Amex: 15 digits, starts with 34, 37
    - MasterCard: 16 digits, starts with 51, 52, 53, 54, 55
    - Visa: 13 and 16 digits, starts with 4
    - Requires keeping track of first two digits of the CC number along with the length of the CC number

**/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {

    long long cc_number;
    int retry = 0;
    int digit_count = 0;

    // Prompt user for CC number, prompt to retry if negative or 0
    do
    {
        if (retry)
        {
            printf("Retry: ");
        }
        else
        {
            printf("Credit Card number: ");
        }

        cc_number = get_long_long();
        retry = 1;
    }
    while (cc_number <= 0);

    // Count digits
    long long cc_copy = cc_number;
    while (cc_copy != 0)
    {
        cc_copy /= 10;
        digit_count++;
    }

    // Checksum calculation, reuse cc_copy
    int odds = 0;
    int evens = 0;

    for (int i = 1; i < digit_count; i++)
    {
        int exponent = pow(10, i);
        int digit = cc_number % exponent;

        while (digit >= 10)
        {
            digit /= 10;
        }

        // Test for even digit
        if (i % 2 == 0)
        {
            printf("Iteration %i is EVEN, using digit %i. ", i, digit);
            evens += digit;
        }

        // Test for odd digit
        else
        {
            printf("Iteration %i is ODD, using digit %i. ", i, digit);
            odds += digit;
        }
    }

    // Identify card type

    // Display results

    printf("Sum of even numbers: %i. Sum of odd numbers: %i.\n", evens, odds);

}