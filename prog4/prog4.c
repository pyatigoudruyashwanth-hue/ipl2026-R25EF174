#include <stdio.h>
#include <stdbool.h>

struct Bitfield {
    unsigned int firstbit : 1; // Allocates exactly 1 bit (values: 0 or 1)
    unsigned int secondbit : 2; // Allocates 2 bits (values: 0 to 3)
    unsigned int thirdbit : 5; // Allocates 5 bits (values: 0 to 31)
};

int main() {
    // 2. Initialize the structure
    struct Bitfield a;

    // 3. Test assigning to the bitfield
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