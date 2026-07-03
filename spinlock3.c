#include <stdbool.h>
bool lock = false;

void some_func() {
    for(;;) {
        spinlock_acquire(&lock);
        //critical section
        spinlock_release(&lock);
    }
}