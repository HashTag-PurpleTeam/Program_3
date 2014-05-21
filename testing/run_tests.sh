#!/bin/sh
# run_tests.sh
#
# Runs our testing scripts.
#
# CREATED: Leland Miller & Craig Collins

mkdir tmp

echo "**********"
echo "# Minix slug_malloc() & slug_free() Tests"


# Test 1
echo
echo "## Test 1 -- This is the standard test"
echo
echo "This test does not have any errors and is the base for our other tests."


./standard_test >1_standard_test.out 2>1_standard_test.err

# Test 2


echo
echo "## Test 2 -- This is the invalid memory test"
echo
echo "This test tries to free memory that was never allocated."

./free_invalid > 2_free_invalid.out 2>2_free_invalid.err

# Test 3

echo
echo "## Test 3 -- This is the already freed memory test"
echo
echo "This test tries to free memory that was already freed."

./free_already_freed > 3_free_already_freed.out 2>3_free_already_freed.err

# Test 4

echo
echo "## Test 4 -- This is the free not first test"
echo
echo "This test tries to free memory with a pointer to the middle of the data."

./free_not_first > 4_free_not_first.out 2>4_free_not_first.err

# Test 5

echo
echo "## Test 5 -- This is the exit without free test"
echo
echo "This test exits without freeing all memory."

./exit_no_free > 5_exit_no_free.out 2>5_exit_no_free.err

echo "Done."
echo "**********"



