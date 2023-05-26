#!/bin/bash

COMPILER=./c_compiler
LLC=llc
GCC=gcc
LLVM=llvm-as
# TEST_FILES=("helloworld" "branch_test" "loop_test" "simple_func_test" "recursive_func_test" "multiply" "quicksort")
TEST_FILES=( "test_loop")

TEST_DIR=../test

for test_file in ${TEST_FILES[@]}; do
    echo "Processing ${test_file}.c ..."
    
    # Generate LLVM IR code
    ${COMPILER} -i ${TEST_DIR}/${test_file}.c -o ${TEST_DIR}/${test_file}.ll 

    ${LLVM} -o=${TEST_DIR}/${test_file}.bc  ${TEST_DIR}/${test_file}.ll

    # Generate object file from assembly
    ${LLC} -filetype=obj -o=${TEST_DIR}/${test_file}.o ${TEST_DIR}/${test_file}.bc

    # Link and create executable
    ${GCC} -no-pie -o ${TEST_DIR}/${test_file} ${TEST_DIR}/${test_file}.o
done

echo "All test files processed."
