#! /bin/bash
COUNT=0
NUM=$#
if [ 1 -gt $# ]; then
	#copy entire folder
	echo "Copying the entire folder."
	cp -r . ../backup
else
	echo "You gave me files: $@"
	args=("$@") # makin a quick array 
	until [ $COUNT -ge $NUM ]; do
                echo "Backing up file $COUNT: ${args[$COUNT]}"
                cp ${args[$COUNT]} ../backup/${args[$COUNT]}
                let COUNT=COUNT+1
	done
fi
