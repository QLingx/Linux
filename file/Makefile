copy:sh error_functions.o get_num.o copy.o
	g++ -o copy error_functions.o get_num.o copy.o
copyo:sh copy.c
	g++ -o copy.c copy.o
error_function:sh error_functions.c
	g++ -g -c error_functions.c error_functions.o
get_num:sh get_num.c
	g++ -g -c get_num.c get_num.o
sh:
	sh Build_ename.sh > ename.c.inc