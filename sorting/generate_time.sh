#!/bin/bash

sorts=(
    selection
    insertion
    bubble
    merge 
    quick
    heap
    counting
    radix
)

start_num="$1"
end_num="$2"
step="$3"
type="$4"
outfile="$5"

if [ -z $start_num ] || [ -z $end_num ] || [ -z $step ] || [ -z $type ] || [ -z $outfile ]  
then
    echo "Usage: ./generate_time.sh <start num> <end num> <step> <type of array> <outfile>"
    echo -e "\ttype of array: choose among [reverse,random]"
    exit 1
fi

rm ${outfile}

for i in "${sorts[@]}"; do
        make time sort="$i"
        ./sort_time ${type} ${start_num} ${end_num} ${step} "$i" ${outfile}
done
