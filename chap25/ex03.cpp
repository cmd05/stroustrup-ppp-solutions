/* Initialize  a  32-bit  signed  integer  with  the  bit  patterns  and  print  the  re-
sult:  all  zeros,  all  ones,  alternating  ones  and  zeros  (starting  with  a  left-
most one), alternating zeros and ones (starting with a leftmost zero), the 
110011001100 . . . pattern, the 001100110011 . . . pattern, the pattern of 
all-one bytes and all-zero bytes starting with an all-one byte, the pattern of 
all-one bytes and all-zero bytes starting with an all-zero byte. Repeat that 
exercise with a 32-bit unsigned integer */

#include <iostream>
#include <iomanip>
#include <vector>

template<typename T>
void pt(std::initializer_list<T> l) {
    for(T x : l) {
        std::cout << std::dec << x << '\t' << std::hex << x << '\n';
    }
}

int main() {
    int x1 = 0x0;
    int x2 = 0xffffffff;
    int x3 = 0xaaaaaaaa;
    int x4 = 0x55555555;
    int x5 = 0xccc; // little endian, eqv to 0x00000ccc
    int x6 = 0x333;
    int x7 = 0xf0f0f0f0;
    int x8 = 0x0f0f0f0f;

    pt<int>({x1,x2,x3,x4,x5,x6,x7,x8});
    std::cout << '\n';
    pt<unsigned int>({x1,x2,x3,x4,x5,x6,x7,x8});
}