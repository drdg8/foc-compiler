#!/bin/bash

COMPILER=./c_compiler
LLC=llc
GCC=gcc
LLVM=llvm-as
# TEST_FILES=( "multiply" "quicksort" "test_array_types" "test_branch" "test_built_in_types" "test_loop" "test_operations" "test_recursive_function" "test_simple_function" )
TEST_FILES=( "quicksort")

TEST_DIR=../test

for test_file in ${TEST_FILES[@]}; do
    echo "Processing ${test_file}.c ..."
    
    # Generate LLVM IR code
    ${COMPILER} -i ${TEST_DIR}/${test_file}.c -o ${TEST_DIR}/${test_file}.ll  -s ${TEST_DIR}/${test_file}.s

    # ${LLVM} -o=${TEST_DIR}/${test_file}.bc  ${TEST_DIR}/${test_file}.ll

    # # Generate object file from assembly
    # ${LLC} -filetype=obj -o=${TEST_DIR}/${test_file}.o ${TEST_DIR}/${test_file}.bc

    # # Link and create executable
    # ${GCC} -no-pie -o ${TEST_DIR}/${test_file} ${TEST_DIR}/${test_file}.o
done

echo "All test files processed."
