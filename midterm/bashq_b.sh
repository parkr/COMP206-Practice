#! /bin/bash
FILES="$@"
echo "keyword: "
read keyword
for f in $FILES
do
	if[-f ${f}.bak ] # asks if the file exists
	then
		continue
	fi
	if[ cat $f | grep -ic $keyword ] then
		cp ${f} ${f}.bak # renames all of the files to have the .bak
	fi
done
