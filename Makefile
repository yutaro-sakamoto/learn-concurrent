all:
	gcc -c cas.c tas.c -S
	gcc -c bad_mutex.c