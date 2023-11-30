#!/bin/bash

input_tests=($(ls ./instances/*.in))

if [ "${#input_tests[@]}" -eq 0 ]; then
	echo "No input tests were found!"
	exit 1
fi

rm -rf "./outputs"
mkdir "./outputs"

make clean
make

for input in "${input_tests[@]}"; do
	file_name="${input##*/}"
	base_name="${file_name%.in}"

	./client < "$input" > "./outputs/$base_name.out"
done

generated_outputs=($(ls ./outputs/*.out))

for output in "${generated_outputs[@]}"; do
	file_name="${output##*/}"
	base_name="${file_name%.out}"
	echo "==== testing $base_name ===="
	diff "./instances/$base_name.out" "$output"
done
