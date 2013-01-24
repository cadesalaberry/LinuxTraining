#!/bin/bash

# Iterates over all the files passed in the arguments
for FILENAME in "$@"
do
	# Checks if the file exists
	if [ -f $FILENAME ]
	then
		# Counts the number of lines (1st part of next expression)
		#WC_OUT=$(wc -l $FILENAME)

		# Extracts only the number of lines from the line count
		NBLINES=$(wc -l $FILENAME | awk '{ NB += $1 } END { print NB }')

		echo $FILENAME : $NBLINES lines, modified on $(date +%Y-%m-%d) >> $FILENAME

		
	fi
done
