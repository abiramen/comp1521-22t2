#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

Word reverse_bits(Word value) {
    
    // value  = 0100 0000 0010 0011
    // mask   = 1000 0000 0000 0000 // 1 << 15
    //          0000 0000 0000 0000
    // when i = 0:
    // is the bit set?
    // if the bit is set, then we will write a 1 to last bit of the result
    // result = 0000 0000 0000 0001
    // when i = 1:
    // value  = 1100 0000 0010 0011
    // mask   = 0100 0000 0000 0000 // 1 << 14
    // since the bit is set, i'm going to update the second-last bit of the result
    // result = 0000 0000 0000 0011
    // when i = 2:
    // mask   = 0010 0000 0000 0000 // 1 << 13
    // the bit isn't set

    Word result = 0;    // 0000 0000 0000 0000
     

    for (int i = 0; i < sizeof(Word) * 8; i++) {
        Word read_mask = 1 << (sizeof(Word) * 8 - 1 - i);
        if (value & read_mask) {
            // this tells me that the bit in the position from the left
            // is set
            Word write_mask = 1 << i;
            result |= write_mask;
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
