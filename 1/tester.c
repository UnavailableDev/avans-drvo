#include <stdio.h>
#include <stdlib.h>

#define fln "/dev/redhue"

int main() {
    FILE *filePointer;
    char text[30] = "hellow";

    // Open file for writing
    filePointer = fopen(fln, "w");

    // Check if file opened successfully
    if (filePointer == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Write to file
    fprintf(filePointer, "%s", text);

    // Close the file
    fclose(filePointer);

    printf("File closed.\n");

    // Open file for reading
    filePointer = fopen(fln, "r");

    // Check if file opened successfully
    if (filePointer == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("Contents of the file:\n");

    // Read and print the content of the file
    while (fgets(text, sizeof(text), filePointer) != NULL) {
        printf("%s", text);
    }

    // Close the file
    fclose(filePointer);

    return 0;
}

