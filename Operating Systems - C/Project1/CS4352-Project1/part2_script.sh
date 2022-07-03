#!/bin/bash

echo -e "\nTesting System Programming w/ Multiple Childs..."
echo -e "\n************************************************"
echo -e "\n\n--- [ Multiple NumChild: 2 ] ---"
./part2_multiple.o 2

echo -e "\n\n--- [ Multiple NumChild: 4 ] ---"
./part2_multiple.o 4

echo -e "\n\n--- [ Multiple NumChild: 8 ] ---"
./part2_multiple.o 8



echo -e "\n\n\nTesting System Programming w/ Chains of Childs..."
echo -e "\n************************************************"
echo -e "\n\n--- [ Chains NumChild: 2 ] ---"
./part2_chains.o 2

echo -e "\n\n--- [ Chains NumChild: 4 ] ---"
./part2_chains.o 4

echo -e "\n\n--- [ Chains NumChild: 8 ] ---"
./part2_chains.o 8

