NAME="./replace"
DIR="tests/"
TEMPFILE="temp_testfile"

C_RESET="\x1b[0m"
C_OK="\x1b[38;2;128;255;0m"
C_KO="\x1b[38;2;255;0;0m"

function	test()
{
	FILE="$DIR$1"
	ERASE="$2"
	INSERT="$3"

	$NAME "$FILE" "$ERASE" "$INSERT" 1> /dev/null;
	sed -i '' 's/"    "/"    "/g'	"$FILE.replace"
	cat $FILE | sed "s/$ERASE/$INSERT/g" > $TEMPFILE
	if [ $(diff "$FILE.replace"	$TEMPFILE | wc -l) -eq 0 ]; then
		echo	$C_OK"OK"$C_RESET"\t"$FILE;
	else
		echo	$C_KO"KO"$C_RESET"\t"$FILE;
		diff "$FILE.replace"	$TEMPFILE;
	fi
	rm	"$FILE.replace"
	rm	"$TEMPFILE";
}

make;

test	test.txt	"ur"	"or";
test	emanuela.txt	"SO"	"So";
test	empty.txt	"SO"	"So";
test	touch.txt	"SO"	"So";
test	newlines0.txt	"upsim"	"ipsum";
test	newlines1.txt	"upsim"	"ipsum";
test	newlines2.txt	"upsim"	"ipsum";
test	newlines3.txt	"upsim"	"ipsum";
test	newlines4.txt	"upsim"	"ipsum";
test	newlines5.txt	"upsim"	"ipsum";
test	newlines6.txt	"upsim"	"ipsum";
test	infinity.txt	"lorem ipsum"	"lorem lorem ipsum";
# test	hollowrm.txt	""	"lorem ipsum";
test	hollowins.txt	"lorem ipsum"	"";
