#include <assert.h>
#include <stdio.h>
#include <stdint.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits

uint32_t reverse_bits(uint32_t value) {
    // value  = 1011 0100
    // result = 0010 1101
    // when i = 0:
    // value   = 1011 0100
    // r_mask  = 1000 0000 // 1 << (NUM_BITS - 1 - i)
    // if (value & mask != 0) the bit has been set
    // result = 0000 0001
    // w_mask = 0000 0100   // 1 << i
    // r | w_m =0000 0101
    // when i = 1
    // value = 1011 0100
    // mask =  0100 0000   // 1 << 6    
    
    int num_bits = sizeof(uint32_t) * 8;
    uint32_t result = 0;


    for (int i = 0; i < num_bits; i++) {
        uint32_t read_mask = 1 << (num_bits - 1 - i);
        if (value & read_mask) {
            uint32_t write_mask = 1 << i;

            result |= write_mask;
            // result = result | write_mask;
        }
    }

    return result;

}

int main(void) {
    assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverse_bits(0x00000000) == 0x00000000);
    assert(reverse_bits(0x1) == 0x80000000);
    assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}
