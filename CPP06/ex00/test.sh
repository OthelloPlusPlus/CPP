make
RET=$?;
if [ $RET -ne 0 ]; then
	echo	"Makefile failed";
	exit $RET;
fi

./convert lorem
./convert c a
./convert 0 -42 42
./convert 332 111 114.2 -155.3 109.00
./convert 0.0f -4.2f 4.2f
./convert -inff +inff nanf
./convert -inf +inf nan
./convert 0 nan 42.0f
./convert 2147483647 2147483648 -2147483648 -2147483649 #int max
./convert 3.40282e+38 1.17550e-38 3.40283e+38 1.17549e-38 #float max
./convert 1.79769e+308 2.22508e-308 1.79770e+308 2.22507e-308 #double max
