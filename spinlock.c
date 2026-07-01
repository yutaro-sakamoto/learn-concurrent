#include <stdbool.h>

void spinlock_acquire(bool* lock) {
    while(test_and_set(lock));
}

void spinlock_release(bool *lock) {
    tas_release(lock);
}