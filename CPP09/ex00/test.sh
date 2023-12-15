#! /bin/zsh
source ../hdr/colors.sh
EXEC="btc"

printf	"$CB_ORANGE$C_BOLD$C_SILVER %-79s$C_RESET\n"	"Exercise 00: Bitcoin Exchange"
make
if [ $? -gt 0 ]; then
	exit 0;
fi

./$EXEC
./$EXEC ""
./$EXEC "$EXEC"
./$EXEC "input.txt"
./$EXEC "file/input.txt"
./$EXEC "file/inputError.txt"
./$EXEC "file/inputDates.txt"
./$EXEC "file/inputValues.txt"
