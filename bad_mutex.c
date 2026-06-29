#include <stdbool.h>
bool lock = false;

void some_func() {
    retry:
        if(!lock) {
            lock = true;
            // do something
        } else {
            goto retry;
        }
        lock = false;
}