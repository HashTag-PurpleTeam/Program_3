CMPS 111 -- Spring 2014
Programming Project #3 -- Allocating Some Memory
Authors: Ryan Gliever, Mat Fukano, Craig Collins, Leland Miller

About:
This program replaces normal malloc() and free() calls with our custom made functions, slug_malloc() and slug_free(). These functions make calls to malloc and free while also storing information about the memory allocations in a singly-linked list. At user program exit, if there are memory leaks detected (if there is memory that has been allocated but not freed), then an error message is printed and slug_memstats() is ran, which displays information about each allocation made. The main purpose of this program is for developers to debug their program in regards to memory leaks.

Building & Running:
With all included files in the same directory, running “make” from the command line should compile all files and run run_tests.sh, which will execute a series of test programs that do different things. Each test program will create a .out file and a .err file; the .out file will show the output of slug_memstats() if it is run, and the .err file will show any error messages that were printed during execution. Each of these can be looked at by running “cat <file>” with file being the selected .out or .err file. EXAMPLE: “cat 1_standard_test.err”

NOTE: If running this program in Ubuntu, you must edit the Makefile and add “-lm” at the end of each of the build lines -- “cc -o …” This includes the math library into the compiler. After this is done, running “make” should build and run the tests normally.


