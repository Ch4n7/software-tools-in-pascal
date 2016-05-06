## PROGRAM

*overstrike*  replaces overstikes by multiple lines

## USAGE

*overstrike*

## FUNCTION

*overstrike* copies its input to its output, replacing lines containing backspaces by multiple lines that overstike to print the same as the input, but contains no backspaces. It is assumed that the output is to be printed on a device that takes the first character of each line as a carriage control; a blank carriage control causes normal space (advance to next line) before print, while a plus sign '+' suppresses spaces (no advance, print on the same line) before printf. and hence causes the reminder of the line to overstrike the previous line.

## BUGS

*overstrike* produces one overstruck line for each sequence of backspaces.
