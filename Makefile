all:
	gcc -S cas.c tas.c
	gcc -c bad_mutex.c
	gcc -c tas.c
	gcc -c good_mutex.c
	gcc -c spinlock.c
	gcc -c spinlock2.c
	gcc -c spinlock3.c
	gcc pthread_mutex_example.c
	gcc -c semaphore.c
