#!/bin/bash
if [ $# -ne 2 ] 
then
    echo "Usage: ./script1.sh inputFile izolatedDir" 
    exit 1
fi
input="$1"
izDir="$2"
while read -r linie 
do
    if grep -Pq '(corrupted|risk|dangerous|attack|malware|[\x80-\xFF])' <<< "$linie"
    then
        mv "$input" "$izDir"
    fi
done < "$input"
