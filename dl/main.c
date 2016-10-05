#include <stdio.h>
#include <dlfcn.h>

typedef int (*func_ptr_t)(int a, int b);
const char* sopath = "/home/twn/github/ApproximateIdentity/module/dl/libtest.so";

int main(void) {
    void* lib = dlopen(sopath, RTLD_LAZY);
    func_ptr_t func = dlsym(lib, "func");
    printf("%d\n", func(1, 2));
    dlclose(lib);
    return 0;
}
