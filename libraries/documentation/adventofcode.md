# Advent of code library

A library containing some basic functions I use to solve the advent of code problems. This library should work on both windows and linux.

## Propeties/Defines

-   `PATH_SEPARATOR`; The line seperator, should allow the code to work on both linux and mac.
For linux there are two defines more, a `__max()` and a `__min()`, these are in the `stdlib.h` of windows, but not on linux, and they're neaded for some functions.

## Structs

-   `filecontent`; Used by the `readfile` function. It contains a 2D string to contain al the info from the file. The struct also contains 2 `long_long_unsigned` variables, one to determine the amount of lines in the file (`lengthfile`), and one to determine the length of the longest string in the file (`maxlengthfile`).

## Global variables

-   `filecontent.file`; Global because there are some functions that fill this specific struct. In advent of code you only get one file you would use at once while running, so 1 global struct should be enough. In the event that ain't enought you can always just define another `filecontent` struct.

## Functions

### File functions

-   `readfile()`; This function reads the file you give with the function. It fills the struct with the content of the file, and also fills the `maxlenghthfile` and `lengthfile`.
-   `fix_file()`; This function runs the `make_file_names`. After this the functions runs the `make_file` function on the two test filenames and the main testfilename, these file should come in the "txt" folder. After making the filenames it runs the `readfile` on the global struct `filecontent.file`, depending if you give `T1`, `T2` or `M` with the function, the filename it uses is different.
-   `make_file_name()`; This function read the filename from the `argv`, and returns the filename.
-   `make_file()`; This function checkes if a file exists, if not it creates the file.
-   `make_debug_file()`; This function makes a debug file in a folder "debug". This function prints makes a .txt file from a 2D array.
-   `make_directory()`; This function makes a directory, if it succeded it prints the directory it created.

### General functions

-   `str_to_llu()`; This function reads a string, and returns a `long long unsigned`.
-   `str_ll()`; This function reads a string, and returns a `long long`.
-   `str_split()`; This function splits the string you give it, it splits the string on a character you chose, and returns a 2D string back.
> [!WARNING]
> This function changes the original string, so if you still need the original, copy the string first

-   `searchAndReplace()`; This function replaces part of a string with another string.
> [!WARNING]
> Be aware, make sure the string you return this function to is big enough for the new string

<!-- Thanks you "JTnadrooi". For your help with reviewing and improving this file -->