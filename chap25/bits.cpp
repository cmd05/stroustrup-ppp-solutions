#include <iostream>
#include <bitset>
using namespace std;

void f(short val) {
    unsigned char right = val&0xff;
    unsigned char left = val>>8;
    unsigned char r2 = val<<8;

    bool negative = val&0x8000;

    std::cout << bitset<8>(left);

    // 0000 0001  1111 0100 (500)
    // 0000 0000  1111 1111
    // 0000 0000  1111 0100 (and)

    // <0000 0000>(not used)  0000 0001 (`unsigned char left`)
    // <1111 0100>(not used)  0000 0000 (`unsigned char r2`) [right to left bits are considered and numbered]
    
    // 0000 0001  1111 0100 (500)
    // 1000 0000  0000 0000 (0x8000)
    // 0000 0000  0000 0000 (and) (`bool negative`) 
}

// out_of_color    16   0x10   0001 0000
// out_of_black    8     0x8   0000 1000
// busy            4     0x4   0000 0100
// paper_empty     2     0x2   0000 0010
// acknowledge     1     0x1   0000 0001

enum Printer_flags { // enumerator names are global as enum is global
    acknowledge=1,
    paper_empty=1<<1,
    busy=1<<2,
    out_of_black=1<<3,
    out_of_color=1<<4, 
};

struct PPN {                     // R6000 Physical Page Number
    unsigned int PFN : 22 ;      // Page Frame Number
    int : 3 ;                    // unused
    unsigned int CCA : 3 ;       // Cache Coherency Algorithm
    bool nonreachable : 1 ;
    bool dirty : 1 ;
    bool valid : 1 ;
    bool global : 1 ;
};

void f2(PPN* p) {
    if(p->dirty) { // contents changed
        // copy to disk
        p->dirty = 0;
    }
    // ...
}

int main()
{
    // unsigned char a = 0xaa;
    // std::cout << bitset<8>{a} << '\n';
    // a <<= 1; // left shift, insert 0 from right side
    // std::cout << bitset<8>{a} << '\n';
    // a >>= 2; // right shift, insert 0,0 from left side
    // std::cout << bitset<8>{a} << '\n';

    // for (unsigned int i; cin>>i; ) 
    //         cout << dec << i << "=="
    //                     << hex << "0x" << i << "=="
    //                     << bitset<8*sizeof(unsigned int)>{i} << '\n';

    // in case bits are less than required number of bits in bitset<n>, leftmost n bits are included
    // and others are truncated off
    // bitset<5> bs {99999};
    // bitset<5> dword_bits {"1010101010101010"};
    // std::cout << bs;

    // auto x = 'a' | 'b';
    // std::cout << typeid(x).name();

    
    // 0000 0000  0000 0000  0000 0001 1001
    //                            0110 0001
    // 0000 0000  0000 0000  0000 0111 1000 // xor

    // unsigned int x = 25;
    // unsigned char c = 'a'; // 97
    // unsigned int res = x ^ c;

    // std::cout << bitset<8*sizeof(unsigned int)>(res);

    // We can use the usual bit manipulation operators for bitsets. Assume that b1, b2, 
    // and b3 are bitsets:
    // b1 = b2&b3;         // and
    // b1 = b2|b3;           // or
    // b1 = b2^b3;          // xor
    // b1 = ~b2;                // complement
    // b1 = b2<<2;          // shift left
    // b1 = b2>>3;          // shift right
    
    // int x = -1;
    // int y = ~x;
    // std::cout << y;

    // unsigned int x = -1; // 4294967295. (bit representation of -1 is copied) (-1 => 0xffffffff => 4294967295)
    // int y = x; // -1 (bit representation is copied)

    // char c = 128;
    // std::cout << int(c);

    // f(500);

    // unsigned char x = out_of_color | out_of_black; // 24 (set bit out_of_color and out_of_black to 1)
    // x |= paper_empty; // 26 (set bit paper_empty 1)

    // if(x & out_of_color) { // is out_of_color set?
        // ...
    // }

    // unsigned char y = x & (out_of_color | out_of_black); 
    //                     // masking, extract quantities out_of_color and out_of_black only from x
    
    // Printer_flags z = Printer_flags(out_of_color | out_of_black);
    // std::cout << z; // 24

    // PPN pn;
    // unsigned int x = pn.CCA; // extract CCA, using bitfields
 
    // unsigned int pni; // assume int stores bits of a PPN register 
    // unsigned int y  = (pni>>4) & 0x7; // manual way, shift and mask
}