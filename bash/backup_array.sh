#! /bin/bash
COUNT=0
NUM=$#
if [ 1 -gt $# ]; then
	#copy entire folder
	echo "Copying the entire folder..."
	cp -r . ../backup
	echo "done."
else
	echo "You gave me file(s): $@"
	args=("$@") # makin a quick array
	#use shift 
	until [ $COUNT -ge $NUM ]; do
		FILENUM=$(($COUNT+1))
                echo "Backing up file $FILENUM: ${args[$COUNT]}"
                cp ${args[$COUNT]} ../backup/${args[$COUNT]}
                let COUNT=COUNT+1
	done
fi
