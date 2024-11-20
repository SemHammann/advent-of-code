# Advent of code library
A library of some basic functions I use too solve the problems of advent of code.

## Defines
`PATH_SEPARATOR` is defined, this is because it is used in some functions. Because of this the code should work too on linux and mac. 

## Structs
The struct `filecontent` is defined. This struct is used by the `readfile` function. It contains a 2D string to contain al the info from the file. The struct also contains 2 `long long unsigned` variables, one to determine the amount of lines in the file (`lengthfile`), and one to determine the length of the longest string in the file (`maxlengthfile`).

## Global variables
### filecontent.file
This is global because there are some functions that fill this specific struct. In advent of code you only get one file you would use at once while running, so 1 global struct should be enough. In the event that ain't enought you can always just define another `filecontent` struct. 

### filenames
These global variables are used by the `fix_file` function. These are used to store the two testfiles, the main file, and the file you want to use in your code. 

## Functions
### readfile
This function reads the file you give with the function. It fills the struct with the content of the file, and also fills the `maxlenghthfile` and `lengthfile`.

### fix_file
This function read the filename from the `argv`. After this it makes two test filenames and a main testfilename. Depending if you have `TEST1` or `TEST2` defined, your main `filename` is chosen (these should be defined before the include, in any other way it defaults to the main file). After making the filenames it runs the `readfile` on the global struct `filecontent.file` with the main `filename`. After this the functions runs the `make_file` function on the two test filenames and the main testfilename.

### make_file
This function checkes if a file exists, if not it creates the file.

### strtoint
This function reads a string, and returns a `long long unsigned`. 

### str_split
This function splits the string you give it, it splits the string on a character you chose, and returns a 2D string back. **Be aware, the function changes the original string, so if you still need the original, copy the string first**

### searchAndReplace
This function replaces part of a string with another string. **Be aware, make sure the string you return this function to is big enough for the new string**