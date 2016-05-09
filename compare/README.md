## PROGRAM

*compare*	compare files for equality

## USAGE

	compare file1 file2

## FUNCTION

*compare* performs a line-by-line comparision of *file1* and *file2*, printing each pair of different lines, preceded by a line containing the offending line number and a colon. If the files are identical, no output is produced. If one file is prefix of the other, *compare* reports end of file on the shorter one.

## EXAMPLE

	compare old new

## BUG

*compare* can produce voluminous output for small differences.
