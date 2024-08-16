# Homework #2 - The Logic Circuit Emulator.

This emulator is binary text based. This means that it reads '1' and '0'
as text and interprets them in the same fashion as digital circuits would.

## Your Task!

Fix the functions in `src/logic.c` and `src/logic32.c` to emulate the
logic described in the code comments.

## READ THE CODE COMMENTS

The code comments do provide pointers to help you implement each
function read them.

## TEST YOUR CODE

The test suite is given and you can check your code by running the tests.
To run the checks run `make test`.

## The Makefile

There are several Makefile targets created for your convenience.

### Build your code

Run `make` to build your code.

### Test your code

Run `make test` to check your code.

### Check for coverage

If you are unsure your code was called by the testing suite, run
`make gcov` to check for code coverage.

### Clean your build directory

To clean out binaries, objects, and other ancillary files run `make clean`.

## Grading

Points will be given to completeness described in the comments in the
code. Make sure your code tests successfully and the test suite has
coverage over your code.
