all:
	gcc -S cas.c tas.c
	gcc -c bad_mutex.c
	gcc -c tas.c
	gcc -c good_mutex.c
