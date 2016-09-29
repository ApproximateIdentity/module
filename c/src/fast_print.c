#include <stdio.h>


void fast_print_strings(const char** strings) {
    int i = 0;
    const char* p;
    while (1) {
        p = *(strings + i++);
        if (p == NULL) {
            break;
        }
        printf("%s\n", p);
    }
}
