#include <stdbool.h>

void spinlock_acquire2(volatile bool *lock) {
    for(;;) {
        while(*lock);
        if(!test_and_set(lock))
            break;
    }
}

void spinlock_release2(bool* lock) {
    tas_release(lock);
}