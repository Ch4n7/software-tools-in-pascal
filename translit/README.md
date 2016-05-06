## PROGRAM

*translit* transliterate characters

## USAGE

*translit* [^]fromset [toset]

## FUNCTION

*translit* maps its input, on a character by character basis, and writes the translated version to its output.

* In the simplest case, each character in the argument *fromset* is translated into the corresponding character in the argument *toset*; all other characters are copied as is. 

* Both *fromeset* and *toset* argument may contain substrings of the form *c1-c2* as the shorthand for all characters in the range of *c1..c2*; *c1* and *c2* must both be digits, or both be letters of the same case.

* If *toset* is shorter than *fromset*, all characters in *fromset* that would map to or beyond the last character in *toset* are mapped to the last character in *toset*; moreover any adjacent instances of such characters in the input are represented by only one instance of the last character in *toset*. Thus `translit 0-9 0` converts each string of digits to the digit `0`.

* Specially, if *toset* is absent, all characters represented by *fromset* will be deleted.

* Finally, if *fromset* is preceded by a '^', all but the characters represented by the *fromset* are taken as the from-set characters

## EXAMPLE

To convert lower case to upper:
	translit a-z A-Z

To reserve only digits:
	translit ^0-9

To produce a Caesar Cipher:
	translit a-z b-za

