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
	gcc posix_semaphore.c
	gcc pthread_cond.c
	gcc barrier.c
	gcc -c spin_rw_lock.c
