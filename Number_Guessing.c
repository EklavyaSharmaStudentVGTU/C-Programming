/*A Program to play a Number Guessing Game */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    
    srand(time(NULL));
    number = rand() % 100 + 1;
    
    printf("Welcome to the Number Guessing Game!\n");
    
    do {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess > number) {
            printf("Your guess is too high! Try again.\n");
        } else if (guess < number) {
            printf("Your guess is too low! Try again.\n");
        }
    } while (guess != number);
    
    printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
    
    return 0;
}
