#include <stdbool.h>

/* spinlock2.c で定義されている関数の宣言 */
void spinlock_acquire2(volatile bool *lock);
void spinlock_release2(bool *lock);

void rwlock_read_acquire(int *rcnt, volatile int *wcnt) {
    for(;;) {
        while(*wcnt);
        __sync_fetch_and_add(rcnt, 1);
        if(*wcnt == 0) {
            break;
        }
        __sync_fetch_and_sub(rcnt, 1);
    }
}

void rwlock_read_release(int *rcnt) {
    __sync_fetch_and_sub(rcnt, 1);
}

void rwlock_write_acquire(bool *lock, volatile int *rcnt, int *wcnt) {
    __sync_fetch_and_add(wcnt, 1);
    while(*rcnt);
    spinlock_acquire2(lock);
}

void rwlock_write_release(bool *lock, int *wcnt) {
    spinlock_release2(lock);
    __sync_fetch_and_sub(wcnt, 1);
}