: ' ===================================||==================================== *\
||																			  ||
||							   Colors and Styles							  ||
||																			  ||
||																			  ||
||																			  ||
||		https://chrisyeh96.github.io/2020/03/28/terminal-colors.html		  ||
||				 https://www.google.com/search?q=color+chooser				  ||
||				  https://en.wikipedia.org/wiki/Tertiary_color				  ||
\* ===============colors===============||==============©Othello============== '

: ' ===================================||==================================== *\
||																			  ||
||									 Reset									  ||
||																			  ||
\* ===============colors===============||==============©Othello============== '
C_RESET="\x1b[0m"
: ' ===================================||==================================== *\
||																			  ||
||									 Styles									  ||
||																			  ||
\* ===============colors===============||==============©Othello============== '
C_BOLD="\x1b[1m"
C_WEAK="\x1b[2m"
C_CURS="\x1b[3m"
C_UNDL="\x1b[4m"
C_BLNK="\x1b[5m"
C_REV="\x1b[7m"
C_HIDDEN="\x1b[8m"

: ' ===================================||==================================== *\
||																			  ||
||									 Colors									  ||
||																			  ||
|| ====================================||==================================== ||
||								   Graytones								  ||
\* ===============colors===============||==============©Othello============== '
C_WHITE="\x1b[38;2;255;255;255m"
C_LGRAY="\x1b[38;2;192;192;192m"
C_GRAY="\x1b[38;2;128;128;128m"
C_DGRAY="\x1b[38;2;64;64;64m"
C_BLACK="\x1b[38;2;0;0;0m"
: ' ====================================||==================================== *\
||									Rainbow									  ||
\* ===============colors===============||==============©Othello============== '
C_LRED="\x1b[38;2;255;128;128m"
C_RED="\x1b[38;2;255;0;0m"
C_DRED="\x1b[38;2;128;0;0m"
C_LORANGE="\x1b[38;2;255;192;128m"
C_ORANGE="\x1b[38;2;255;128;0m"
C_DORANGE="\x1b[38;2;128;64;0m"
C_LYELLOW="\x1b[38;2;255;255;128m"
C_YELLOW="\x1b[38;2;255;255;0m"
C_DYELLOW="\x1b[38;2;128;128;0m"
C_LCHRT="\x1b[38;2;192;255;128m"
C_CHRT="\x1b[38;2;128;255;0m"	#chartreuse
C_DCHRT="\x1b[38;2;64;128;0m"
C_LGREEN="\x1b[38;2;128;255;128m"
C_GREEN="\x1b[38;2;0;255;0m"
C_DGREEN="\x1b[38;2;0;128;0m"
C_LSPRGR="\x1b[38;2;128;255;192m"
C_SPRGR="\x1b[38;2;0;255;128m"	#spring green
C_DSPRGR="\x1b[38;2;0;128;64m"
C_LCYAN="\x1b[38;2;128;255;255m"
C_CYAN="\x1b[38;2;0;255;255m"
C_DCYAN="\x1b[38;2;0;128;128m"
C_LAZURE="\x1b[38;2;0;192;255m"
C_AZURE="\x1b[38;2;0;128;255m"
C_DAZURE="\x1b[38;2;0;64;128m"
C_LBLUE="\x1b[38;2;128;128;255m"
C_BLUE="\x1b[38;2;0;0;255m"
C_DBLUE="\x1b[38;2;0;0;128m"
C_LVIOLET="\x1b[38;2;192;0;255m"
C_VIOLET="\x1b[38;2;128;0;255m"
C_DVIOLET="\x1b[38;2;64;0;255m"
C_LMGNT="\x1b[38;2;255;128;255m"
C_MGNT="\x1b[38;2;255;0;255m"	#magenta
C_DMGNT="\x1b[38;2;128;0;128m"
C_LROSE="\x1b[38;2;255;128;192m"
C_ROSE="\x1b[38;2;255;0;128m"
C_DROSE="\x1b[38;2;128;0;64m"
: ' ===================================||==================================== *\
||								 Common Colors								  ||
\* ===============colors===============||==============©Othello============== '
C_LBROWN="\x1b[38;2;192;144;96m"
C_BROWN="\x1b[38;2;128;64;0m" #hue 30
C_DBROWN="\x1b[38;2;64;32;0m"
C_LPURPLE="\x1b[38;2;192;96;192m"
C_PURPLE="\x1b[38;2;128;0;128m" #hue 300
C_DPURPLE="\x1b[38;2;64;0;64m"
C_LPINK="\x1b[38;2;255;224;229m"
C_PINK="\x1b[38;2;255;192;203m" #hue 350
C_DPINK="\x1b[38;2;128;48;62m"
: ' ===================================||==================================== *\
||								  Prized Metal								  ||
\* ===============colors===============||==============©Othello============== '
C_BRONZE="\x1b[38;2;205;127;50m"
C_SILVER="\x1b[38;2;192;192;192m"
C_GOLD="\x1b[38;2;255;215;0m"
: ' ===================================||==================================== *\
||																			  ||
||								  Backgrounds								  ||
||																			  ||
|| ====================================||==================================== ||
||								   Graytones								  ||
\* ===============colors===============||==============©Othello============== '
CB_WHITE="\x1b[48;2;255;255;255m"
CB_LGRAY="\x1b[48;2;192;192;192m"
CB_GRAY="\x1b[48;2;128;128;128m"
CB_DGRAY="\x1b[48;2;64;64;64m"
CB_BLACK="\x1b[48;2;0;0;0m"
: ' ===================================||==================================== *\
||									Rainbow									  ||
\* ===============colors===============||==============©Othello============== '
CB_LRED="\x1b[48;2;255;128;128m"
CB_RED="\x1b[48;2;255;0;0m"
CB_DRED="\x1b[48;2;128;0;0m"
CB_LORANGE="\x1b[48;2;255;192;128m"
CB_ORANGE="\x1b[48;2;255;128;0m"
CB_DORANGE="\x1b[48;2;128;64;0m"
CB_LYELLOW="\x1b[48;2;255;255;128m"
CB_YELLOW="\x1b[48;2;255;255;0m"
CB_DYELLOW="\x1b[48;2;128;128;0m"
CB_LCHRT="\x1b[48;2;192;255;128m"
CB_CHRT="\x1b[48;2;128;255;0m" #chartreuse
CB_DCHRT="\x1b[48;2;64;128;0m"
CB_LGREEN="\x1b[48;2;128;255;128m"
CB_GREEN="\x1b[48;2;0;255;0m"
CB_DGREEN="\x1b[48;2;0;128;0m"
CB_LSPRGR="\x1b[48;2;128;255;192m"
CB_SPRGR="\x1b[48;2;0;255;128m"	#spring green
CB_DSPRGR="\x1b[48;2;0;128;64m"
CB_LCYAN="\x1b[48;2;128;255;255m"
CB_CYAN="\x1b[48;2;0;255;255m"
CB_DCYAN="\x1b[48;2;0;128;128m"
CB_LAZURE="\x1b[48;2;0;192;255m"
CB_AZURE="\x1b[48;2;0;128;255m"
CB_DAZURE="\x1b[48;2;0;64;128m"
CB_LBLUE="\x1b[48;2;128;128;255m"
CB_BLUE="\x1b[48;2;0;0;255m"
CB_DBLUE="\x1b[48;2;0;0;128m"
CB_LVIOLET="\x1b[48;2;192;0;255m"
CB_VIOLET="\x1b[48;2;128;0;255m"
CB_DVIOLET="\x1b[48;2;64;0;255m"
CB_LMGNT="\x1b[48;2;255;128;255m"
CB_MGNT="\x1b[48;2;255;0;255m"	#magenta
CB_DMGNT="\x1b[48;2;128;0;128m"
CB_LROSE="\x1b[48;2;255;128;192m"
CB_ROSE="\x1b[48;2;255;0;128m"
CB_DROSE="\x1b[48;2;128;0;64m"
: ' ===================================||==================================== *\
||								 Common Colors								  ||
\* ===============colors===============||==============©Othello============== '
CB_LBROWN="\x1b[48;2;192;144;96m"
CB_BROWN="\x1b[48;2;128;64;0m" #hue 30
CB_DBROWN="\x1b[48;2;64;32;0m"
CB_LPURPLE="\x1b[48;2;192;96;192m"
CB_PURPLE="\x1b[48;2;128;0;128m" #hue 300
CB_DPURPLE="\x1b[48;2;64;0;64m"
CB_LPINK="\x1b[48;2;255;224;229m"
CB_PINK="\x1b[48;2;255;192;203m" #hue 350
CB_DPINK="\x1b[48;2;128;48;62m"
: ' ===================================||==================================== *\
||								  Prized Metal								  ||
\* ===============colors===============||==============©Othello============== '
CB_BRONZE="\x1b[48;2;205;127;50m"
CB_SILVER="\x1b[48;2;192;192;192m"
CB_GOLD="\x1b[48;2;255;215;0m"
: ' ===================================||==================================== *\
||																			  ||
||								 Miscellaneous								  ||
||																			  ||
\* ===============colors===============||==============©Othello============== '
C_HEADER="\x1b[48;2;85;85;85m \x1b[48;2;139;139;139m \
\x1b[48;2;192;192;192m \x1b[48;2;255;128;0m \x1b[1m\x1b[38;2;0;0;0m"
C_SUBHEAD="\x1b[48;2;85;85;85m \x1b[48;2;139;139;139m \
\x1b[48;2;192;192;192m \x1b[1m\x1b[38;2;0;0;0m"
C_OK="\x1b[38;2;16;223;16m"
