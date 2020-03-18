#!/bin/bash

n=10
while [ $n -le 1000000 ]
do
    ./compareSort lab_sheet/$n ${n}.out
    n=$((n*10))
done
