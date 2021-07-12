#include <stdio.h>

extern int teste_1();
extern int teste_2();

int main (){
    unsigned int x, y, z;

    printf("\n");    

    x = teste_1();
    printf("x: %u \n", x);    
    
    x = teste_1();
    printf("x: %u \n", x);    
    
   
    teste_2(x + 100);

    y = teste_1();

    z = y - x;
    printf("z: %u \n", z);

    printf("y: %u \n", y);

    return 0;
}