#! /bin/zsh
source ../hdr/colors.sh
EXEC="RPN"

function testFile()
{
	printf	"$CB_SILVER$C_BOLD Testing %-42s$C_RESET\n"	"$1"
	while IFS="" read -r LINE; do
		printf	"$CB_DORANGE$C_BOLD Calculating: [%s]$C_RESET\n"	"$LINE"
		./$EXEC "$LINE"
	done < "$1"
}

printf	"$CB_ORANGE$C_BOLD$C_SILVER %-79s$C_RESET\n"	"Exercise 01: Reverse Polish Notation"

make
if [ $? -gt 0 ]; then
	exit 0;
fi

testFile "file/subject.txt"
testFile "file/error.txt"
testFile "file/manual.txt"
