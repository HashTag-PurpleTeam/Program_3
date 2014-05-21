#!/bin/sh
# run_tests.sh
#
# Runs our testing scripts.
#
# CREATED: Leland Miller & Craig Collins

mkdir tmp

echo "**********"
echo "# Minix slug_malloc() & slug_free() Tests"

# Compile Tests
echo
echo "Compile the Tests."

cc -c standard_test.c -o standard_test
cc -c free_invalid.c -o free_invalid
cc -c free_already_freed.c -o free_already_freed
cc -c free_not_first.c -o free_not_first
cc -c exit_no_free.c -o exit_no_free

# Test 1
echo
echo "## Test 1"
echo
echo "This test does not have any errors and is the base for our other tests."


./standard_test >1_standard_test.out 2>1_standard_test.err

# Test 2


echo
echo "## Test 2"
echo
echo "This test tries to free memory that was never allocated."

./free_invalid > 2_free_invalid.out 2>2_free_invalid.err

# Test 3

echo
echo "## Test 3"
echo
echo "This test tries to free memory that was already freed."

./free_already_freed > 3_free_already_freed.out 2>3_free_already_freed.err

# Test 4

echo
echo "## Test 4"
echo
echo "This test tries to free memory with a pointer to the middle of the data."

./free_not_first > 4_free_not_first.out 2>4_free_not_first.err

# Test 5

echo
echo "## Test 5"
echo
echo "This test exits without freeing all memory."

./exit_no_free > 5_exit_no_free.out 2>5_exit_no_free.err

echo "Done."
echo "**********"



