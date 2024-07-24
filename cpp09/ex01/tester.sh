#!/bin/bash

# Array of RPN expressions
expressions=(
  "3 4 +"
  "5 1 2 + 4 * + 3 -"
  "2 3 * 5 4 * +"
  "6 2 / 3 +"
  "7 8 + 3 2 * /"
  "9 3 - 2 4 * +"
  "5 6 2 + *"
  "4 2 + 3 1 - /"
  "3 5 8 * 7 + *"
  "2 4 3 + *"
  "8 2 5 * + 1 3 2 * + 4 - /"
  "7 2 3 * -"
  "6 2 3 + *"
  "4 5 + 2 *"
  "9 3 1 - /"
  "5 1 2 + 3 * -"
  "8 2 3 / +"
  "7 4 2 * + 1 -"
  "3 6 9 + 2 * /"
  "2 5 3 + * 4 -"
  "2 5 3 + * 4 - 3 6 + 9 + 2 * / 9 3 * 1 - /"
)

# Expected results for the RPN expressions
expected_results=(
  7
  14
  26
  6
  2.5
  14
  40
  3
  141
  14
  6
  1
  30
  18
  4.5
  -4
  8.66667
  14
  0.1
  12
  0.0128205
)

# Length of the expressions array
len=${#expressions[@]}

# Loop through each RPN expression and test it
for (( i=0; i<$len; i++ )); do
  result=$(./rpn "${expressions[$i]}")
  if [ "$result" == "${expected_results[$i]}" ]; then
    echo -e "CORRECT\n"
  else
    echo -e "INCORRECT\nInput: ${expressions[$i]}\nYour output: $result\nExpected: ${expected_results[$i]}\n"
  fi
done
