#! /bin/bash
set -x

file=/home/somnath/0/OS/Scripting/file.txt

trap "echo Exit command detected" 0

trap "rm -f $file; echo Deleted; exit" SIGINT SIGTERM

trap "echo SIGKILL" SIGKILL #not captured

set +x

echo pid is $$
while (( COUNT < 10 ))
do
	sleep 1
	(( COUNT++ ))
	echo $COUNT
done
exit 0