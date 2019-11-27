#!/bin/bash

N=( 150000 300000 600000 1200000 2400000 4800000 7200000 9600000 10800000 14400000 19200000 21600000)

K=$1

if [ $K = 1 ]; then
    TREE="linear"
elif [ $K = 2 ]; then
    TREE="binary"
elif [ $K = 4 ]; then
    TREE="4ary"
fi

for n in ${N[@]}
do
    echo $n
    FILE="input/${TREE}/query_${TREE}_${n}"
    touch $FILE
    ./query_generator $n $K
done