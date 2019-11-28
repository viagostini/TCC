#!/bin/bash

Q=(7500 12500 22500 37500 52500)
M=(1000 2500 5000 7500 10000 12500 15000 22500 30000 37500 45000 52500)
N=(150000 300000 600000 1200000 2400000 4800000 7200000 9600000 10800000 14400000 19200000 21600000)

ALGO=$1
K=$2


if [ $K = 1 ]; then
    TREE="linear"
elif [ $K = 2 ]; then
    TREE="binary"
elif [ $K = 4 ]; then
    TREE="4ary"
fi

for n in ${M[@]}
do
    echo $n
    FILE="results/${TREE}_query/${ALGO}_${TREE}_${n}_query.txt"
    touch $FILE
    for ((i=1; i<=10; i++))
    do
        ./${ALGO}_query_bench $n $K >> $FILE
    done
done