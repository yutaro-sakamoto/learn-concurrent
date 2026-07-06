const int NUM = 3;
void semaphore_acquire(volatile int *cnt) {
    for(;;) {
        while(*cnt >= NUM);
        __sync_fetch_and_add(cnt, 1);
        if(*cnt <= NUM) {
            break;
        }
        __sync_fetch_and_sub(cnt, 1);
    }
}

void semaphore_release(int *cnt) {
    __sync_fetch_and_sub(cnt, 1);
}

int cnt = 0;

void some_func() {
    for(;;) {
        semaphore_acquire(&cnt);
        // process data
        semaphore_release(&cnt);
    }
}