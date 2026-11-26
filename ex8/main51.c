#include <stdio.h>

int main() {
    int var[5] = {1, 10, 100, 1000, 10000};
    int* ip = NULL;

    ip = var;

    printf("%p\n", (void*)var);
    printf("%p\n", (void*)&var[0]);
    printf("%p\n", (void*)&var);
    printf("%p\n", (void*)ip);

    return 0;
}