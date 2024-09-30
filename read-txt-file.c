#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
    // Defining file pointer and opening the file.
    FILE *file_ptr;
    char str[50];

    // a+ Mode Means that the file is opened in the
    // append + reading mode
    file_ptr = fopen("1.txt", "r");

    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }

      // Reading stinrg using fgets
    printf("Content of this file are: \n");
    while (fgets(str, 50, file_ptr) != NULL) {
        printf("%s", str);
    }

    fclose(file_ptr);
    return 0;
}