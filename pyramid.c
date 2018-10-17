/*
Half-Pyramid drawing
--------------------

Task:
- Height must be positive, from 0 min to 23 max.
- Use cs50.h for the get_int() function
- 1 Print one half of the pyramid
- 2 Two (always two) spaces
- 3 Print other half of the pyramid

**/

#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int height;

    // Get input from user
    do
    {
        printf("Enter a height, from 0 to 23: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    // Iterate over each line
    for (int i = 1; i < height + 1; i++)
    {
        // Spaces
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Hashes ... use `for (int j = 0; j < i * 2; j++)` to make the pyramid full instead of half
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Gap, always 2 spaces
        printf("  ");

        // Second half of the pyramid. This code sure ain't DRY!
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // New line
        printf("\n");
    }
}