#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using    namespace std;

int main() {
    uint64_t a = 0x8070605040302010;
    // 10 20 30 40 50 60 70 80
    char *p = (char *)&a;
    uint16_t *p16 = (uint16_t*)(p+1);

    printf("0x%x", *(p16+2));
    return 0;
}