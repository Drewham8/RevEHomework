#!/bin/bash

main(){
    isCorrect=0
    count=0
    while [ $isCorrect -eq 0 ] ;do
             LOAD=`head /dev/urandom | tr -dc A-Za-z | head -c 16`
             SUM=`echo $LOAD | gawk -l ordchr -v RS='.{1}' 'BEGIN{s=0} {s+=ord(RT)} END{print s+0}'`
             XORSUM=0

             XORSUM=`echo $LOAD | gawk -l ordchr -v RS='.{1}' 'BEGIN{s=0} {s=xor(s,ord(RT))} END{print s+0}'`
             MASK=0xA
             XORSUM=$(($XORSUM^$MASK))
             SUM=$(expr $SUM % 256)
             SUM=$(($SUM-10))
             TOTAL=$(($SUM+$XORSUM))
             if [ $TOTAL -eq 216 ]
             then
                 isCorrect=1
             fi
    done
    ./maze E U $LOAD S W S E U
}

main;exit
