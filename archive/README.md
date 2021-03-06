## PROGRAM

*archive*	maintain file archive

## USAGE

	archive -cmd aname [ file ... ]

## FUNCTION

*archive* manages any number of member files in a single file, aname, with sufficient information that members may selectively added, extracted, replaced, or deleted from the collection. `-cmd` is a code that determines the operation to be performed:

* `-c` create a new archive with named members
* `-d` delete named members from archive
* `-p` print named members on standard output
* `-t` print table of archive contents
* `-u` update named members or add at end
* `-x` extract named members from archive

In each case, the "named members" are the zero or more filenames given as arguments following aname. If no arguments follow, then the "named members" are taken as all of the files in the archive, except for the delete command `-d`, which is not so rash. *archive* complains if a file is named twice or cannot be accessed.

The `-t` command writes one line to the output for each named member, consisting of the member name and a string representation of the file length, separated by a blank.

The create command `-c` makes a new archive containing the named files. The update command `-u` replaces existing named members and adds new files onto the end of an existing archive. Create and update read from, and extract writes to, files whose names are the same as the member names in the archive. An intermediate version of the new archive file is first written to the file *artemp*; hence this filename should be avoided.

An archive is concatenation of zero or more entries, each consisting of a header and exact copy of the original file. The header format is

	-h- name length

## EXAMPLE

To replace two files in an existing archive, add a new one, then print the table of contents:

	archive -u archfile old1 old2 new1
	archive -t archfile
