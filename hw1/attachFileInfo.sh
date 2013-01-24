#!/bin/bash

# Iterates over all the files passed in the arguments.
for FILENAME in "$@"
do
	# Checks if the file exists.
	if [ -f $FILENAME ]
	then
		# Counts the number of lines in the file.
		NBLINES=$(cat $FILENAME | grep -c ^)
		
		# Gets the current date.
		DATE=$(date +%Y-%m-%d)

		echo $FILENAME : $NBLINES lines, modified on $DATE >> $FILENAME

	else
		echo File $FILENAME does not exist.
	fi
done
