# Advent of code library

A library containing some basic functions I use to solve the advent of code problems. This library should work on both windows and linux.

## Functions

### General functions

-   `str_to_llu()`; This function reads a string, and returns a `long long unsigned`.
-   `str_ll()`; This function reads a string, and returns a `long long`.
-   `str_split()`; This function splits the string you give it, it splits the string on a character you chose, and returns a 2D string back.
> [!WARNING]
> This function changes the original string, so if you still need the original, copy the string first

-   `searchAndReplace()`; This function replaces part of a string with another string.
> [!WARNING]
> Be aware, make sure the string you return this function to is big enough for the new string