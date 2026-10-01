#include <stdio.h>

int main()
{
    char a = 'B';
    printf("Your grade is %c\n", grade);
    switch(grade){
    case 'A' :
        printf("Excellent!\n");
        break;
    case 'B' :
    case 'C' :
        printf("Well done!\n");
        break;
    case 'D' :
    case 'F' :
        printf("Better try again!\n");
        break;
    default:
        printf("invalid grade\n");
    }

    return 0;
}
