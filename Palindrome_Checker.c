#include <stdio.h>  
#include <string.h> 

/**
 * Checks if a given string is a palindrome.
 */
int isPalindrome(const char* str) {
    int length = strlen(str);  // Get the length of the string.

    // Iterate over the string from both ends and compare the characters.
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;  // Characters don't match, not a palindrome.
        }
    }

    return 1;  // All characters match, it's a palindrome.
}

int main() {
    char str[100];  // Declare a character array to store the input string.

    printf("Enter a string: ");
    scanf("%s", str);  // Read the input string from the user.

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}