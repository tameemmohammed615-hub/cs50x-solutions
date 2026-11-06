#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt user for height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print rows
    for (int i = 0; i < height; i++)
    {
        // Print leading spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print left hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print gap between pyramids
        printf("  ");

        // Print right hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}
