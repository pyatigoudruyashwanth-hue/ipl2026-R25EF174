#include <stdio.h>
#include <stdbool.h>

struct Bitfield {
    unsigned int firstbit : 1; 
    unsigned int secondbit : 2; 
    unsigned int thirdbit : 5; 
};

int main() {
    
    struct Bitfield a;
    a.firstbit = 1;
    a.secondbit = 3;
    a.thirdbit = 17;
    
    printf("firstbit: %u\n", a.firstbit);
    printf("status: %u\n", a.secondbit);
    printf("flags: %u\n", a.thirdbit);
    a.firstbit = 3;
    printf("firstbit after overflow (setting to 3): %u\n", a.firstbit);
    return 0;
}