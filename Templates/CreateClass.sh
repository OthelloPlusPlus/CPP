#! /bin/bash

CPPTemplate="ClassTemplate.cpp"
HPPTemplate="ClassTemplate.hpp"

if [ ! -f "$CPPTemplate" ]; then
	echo "$CPPTemplate is not found."
	exit 1
elif [ ! -f "$HPPTemplate" ]; then
	echo "$HPPTemplate is not found"
	exit 1
fi

echo -n "Class Name: "
read ClassName
CLASSNAME=$(echo "$ClassName" | tr '[:lower:]' '[:upper:]')
echo -n "Location: "
read Location

if [ ! -d "$Location" ]; then
	echo "Location '$Location' not found, create [y/n]? "
	read query
	if [ "$query" = "y" ]; then
		mkdir $Location
		if [ $? -ne 0 ]; then
			exit $?
		fi
	else
		exit 0
	fi
fi

ConvertFile()
{
	SRC=$1
	DST=$2

	if [ -f $DST ]; then
		echo -n "File '$DST' already exists, overwrite [y/n]? ";
		read query
		if [ "$query" != "y" ]; then
			echo "Exiting to avoid overwriting."
			exit 1
		fi
	fi
	cat $SRC | sed "s/ClassName/$ClassName/g" | \
				sed "s/CLASSNAME/$CLASSNAME/g" | \
				sed "s|0000/00/00 00:00:00|$TimeStamp|g" > $DST
}

TimeStamp=$(date +"%Y/%m/%d %H:%M:%S")
ConvertFile "$CPPTemplate" "$Location/$ClassName.cpp"
ConvertFile "$HPPTemplate" "$Location/$ClassName.hpp"
