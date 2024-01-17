#! /bin/zsh
source ../hdr/colors.sh
EXEC="PmergeMe"

function randomTest()
{
	./$EXEC `shuf -i 1-100000 -n $1 | tr "\n" " "`
	ERROR=$?
	if [ $ERROR != 0 ]; then
		printf	"$C_RED Error:$C_RESET %s\n"	"$ERROR"
		exit $ERROR
	fi
}

printf	"$CB_ORANGE$C_BOLD$C_SILVER %-79s$C_RESET\n"	"Exercise 02: PmergeMe"

make
if [ $? -gt 0 ]; then
	exit 0;
fi

./$EXEC
./$EXEC	""
./$EXEC	"lorem"
./$EXEC -1 2
./$EXEC 3 5 9 7 4
./$EXEC 1 3 5 2 4 6 0
./$EXEC 1 3 5 7 2 4 6 0
./$EXEC 1 3 5 7 2 4 6 8 0
./$EXEC 1 3 5 7 9 2 4 6 8 0
./$EXEC 0 1 2 3 4 5 6 7 8 9
./$EXEC 9 8 7 6 5 4 3 2 1 0
./$EXEC 0 0 1 0 1 2 0 1 2 3
./$EXEC +2 +3 +4 +2
randomTest 0
randomTest 1
randomTest 2
randomTest 3
randomTest 4
randomTest 5
randomTest 7
randomTest 23
randomTest 42
randomTest 3000
randomTest 10000
# randomTest 100000
