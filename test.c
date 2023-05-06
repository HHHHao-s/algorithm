#include <stdio.h>

struct test{
    unsigned char a;
    unsigned short b;
    unsigned char c;
}__attribute__((packed));

int main(){

    unsigned int a = 0x87654321;

    struct test t=*(struct test*)&a;

    printf("%x", t.b);

    

    return 0;
}