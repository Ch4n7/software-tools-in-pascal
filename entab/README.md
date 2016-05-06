## PROGRAM

entab	convert runs of spaces into tabs

## USAGE

entab

## FUNCTION

*entab*copies its input to output, replacing strings of SPACEs by TABs so that the output is visually the same as the input, but contains fewer characters. Each sequence of SPACEs ending on a tab stop will be replaced by a TAB. *entab* can handle the input with TABs, BACKSAPCEs.

## BUGS

* *entab* is naive about backspaces, vertical motions, and non-printing characters.

