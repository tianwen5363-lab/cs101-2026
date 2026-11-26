#include <stdio.h>

int add_func(int a, int b) {
    return a+b;
}

int main() {
    int n = 10, m = 1;
    int (*func_ptr)(int, int);

    func_ptr = add_func;

    printf("%d\n", func_ptr(n, m));

    return 0;
}