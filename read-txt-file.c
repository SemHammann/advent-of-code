#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
    // Defining file pointer and opening the file.
    FILE *file_ptr;
    char str[500];

    // a+ Mode Means that the file is opened in the
    // append + reading mode
    file_ptr = fopen("1.txt", "r"); //put here the file name you need to open

    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }

      // Reading stinrg using fgets
    printf("File open worked\n");
    while (fgets(str, 500, file_ptr) != NULL) {
        printf("%s", str);
    }

    fclose(file_ptr);
    return 0;
}