#!/usr/bin/bash 

set -x
file=/mnt/d/studies/visual_studio_code/bash_script/new.txt
set +x

trap "rm -f $file; exit" 0 2 15

echo "pid is $$"
while (( COUNT < 10 ))
do 
    sleep 10
    (( COUNT++ ))
    echo $COUNT
done
exit 0