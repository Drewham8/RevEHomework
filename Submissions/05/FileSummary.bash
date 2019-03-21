#!/bin/bash
counter=0;
instruction=`head -1 $1`;

shopt -s extglob
instruction=${instruction##*( )}

while read -r line;
do
    if [ ${line##*( )} == $instruction ]
    then
        ((counter++))
    else
        echo "$instruction $counter" >> NewCountFile
        instruction=("${line##*( )}")
        counter=1
    fi
done < "$1"
shopt -u extglob
