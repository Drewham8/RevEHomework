#!/bin/bash
declare -A instructionset
instructionset=( [mov]=0 )

while read -r line;
do
    if [[ ${instructionset[$line]+1} -eq 1 ]]
    then
        instructionset[$line]=$(expr ${instructionset[$line]} + 1)
    else
        instructionset[$line]+=1;
    fi
    
done < "$1"

for i in "${!instructionset[@]}"
do
    echo -n "$i " >> New_file_Counted 
    echo ${instructionset[$i]} >> New_file_Counted 
done
