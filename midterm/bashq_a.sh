#! /bin/bash
FILES="$@"
echo "keyword: "
read keyword
for f in $FILES
do
	if[-f ${f}.bak ] # asks if this is a file
		then
		cat ${f}.bak | grep -i $keyword # if .bak extension at the end of the filename, then they look for the keyword
		continue
	fi
	mv ${f} ${f}.bak # renames all of the files to have the .bak
done
