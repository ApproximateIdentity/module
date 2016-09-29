#include <fast_print.h>
#include <stdlib.h> // For NULL


int main(void) {
    const char* s1 = "hello";
    const char* s2 = "world";
    const char* strings[] = { s1, s2, NULL };
    fast_print_strings(strings);
    return 0;
}
