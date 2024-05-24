#include <stdio.h>

/**
 * Generates a pyramid of asterisks.
 * height: The height of the pyramid.
 **/

void generatePyramid(int height) {
    int i, j, space;

    // Loop to print rows of the pyramid.
    for (i = 1; i <= height; i++) {
        // Loop to print spaces before the asterisks.

        for (space = 1; space <= height - i; space++) {
            printf(" ");
        }

        // Loop to print asterisks.
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");  // Move to the next line after printing each row.
    }
}

int main() {
    int height;

    printf("Enter the height of the pyramid: ");
    scanf("%d", &height);

    generatePyramid(height);

    return 0;
}