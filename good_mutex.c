#include <stdbool.h>

extern bool test_and_set(volatile bool *p);
bool lock = false;

void some_func() {
retry:
    if(!test_and_set(&lock)) {
        // ここにクリティカルセクション
    } else {
        goto retry;
    }
    tas_release(&lock);
}