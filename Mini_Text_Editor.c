#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void openFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char text[MAX_TEXT_LENGTH];
    while (fgets(text, MAX_TEXT_LENGTH, file) != NULL) {
        printf("%s", text);
    }

    fclose(file);
}

void saveFile(char* filename, char* text) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving file.\n");
        return;
    }

    fprintf(file, "%s", text);

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char text[MAX_TEXT_LENGTH];
    int choice;

    printf("Welcome to the Text Editor\n");
    printf("1. Create a new file\n");
    printf("2. Open a file\n");
    printf("3. Write to the file\n");
    printf("4. Edit the file\n");
    printf("5. Save the file\n");
    printf("6. Delete the file\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the filename to create: ");
            scanf("%s", filename);
            FILE* newFile = fopen(filename, "w");
            if (newFile == NULL) {
                printf("Error creating file.\n");
                return 1;
            }
            fclose(newFile);
            printf("File created successfully.\n");
            break;
        case 2:
            printf("Enter the filename to open: ");
            scanf("%s", filename);
            openFile(filename);
            break;
        case 3:
            printf("Enter the filename to write to: ");
            scanf("%s", filename);
            printf("Enter text to write to the file:\n");
            scanf(" %[^\n]s", text);
            saveFile(filename, text);
            printf("Text written to the file.\n");
            break;
        case 4:
            printf("Enter the filename to edit: ");
            scanf("%s", filename);
            openFile(filename);
            printf("\nEnter text to edit (Ctrl + D to save and exit):\n");
            while (fgets(text, MAX_TEXT_LENGTH, stdin) != NULL) {
                // Continue editing text
            }
            saveFile(filename, text);
            printf("File saved successfully.\n");
            break;
        case 5:
            printf("Enter the filename to delete: ");
            scanf("%s", filename);
            if (remove(filename) == 0) {
                printf("File deleted successfully.\n");
            } else {
                printf("Error deleting file.\n");
            }
            break;
        default:
            printf("Invalid choice. Exiting the Text Editor.\n");
            break;
    }

    return 0;
}