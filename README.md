# Simple SGML Scanner
A rudimentary scanner built in C with Flex to parse tokens from Standard Generalized Markup Language documents. The scanner keeps track of "relevant" tags consisting of "TEXT", "DATE", "DOC", "DOCNO", "HEADLINE", "LENGTH", and "P", and only prints out tokens found between these relevant tags. If a tag is incorrectly closed, an error will be displayed. After the scanner is complete, a list of unclosed tags will also be listed.
## Improvements
While developing the scanner, I overlooked tracking tags that are considered "relevant" and "irrelevant", as the first "working" version of the scanner printed out all proper tags. This oversight resulted in using an int variable to track when an open irrelevant tag was used, and increment accordingly as tags were nested deeper inside the irrelevant tag. If I were to redo this assignment, I would refactor this entire portion and instead modify my stack strucures to hold information about which tags were considered irrelevant (or considered relevant but inside a set of irrelvant tags).
## Build/Compile
To build and compile the scanner, run:
```sh
make
```
## Test files
Test files were developed over the course of the development process. Three files were leftover that aimed to cover ideal and error cases. To execute a series of all three tests, run:
```sh
make test
```
## Run scanner on newsdata.txt
To test the provided test file, separate commands were included. To test newsdata.txt and print out, run:
```sh
make run
```
To test newsdata.txt and print out to sample.out, run:
```sh
make run_out
```
## Run scanner on external files
To run the scanner on your own files, send a document with SGML formatting to the stdin on the program with:
```sh
./scanner < your_file.txt
```
# Cleanup
To simply cleanup the compiled files and scanned output, run:
```sh
make clean
```