#include <stdio.h>

int main() {
    int var = 20;
    int* ip;

    ip = &var;

    printf("Address of var: %p\n", (void*)&var);
    printf("Value of ip: %p\n", (void*)ip);
    printf("Address of ip: %p\n", (void*)&ip);
    printf("Value of *ip: %d\n", *ip);

    return 0;
}