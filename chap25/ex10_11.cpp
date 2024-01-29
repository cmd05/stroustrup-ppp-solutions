/* Look at the bitfield example from §25.5.5. Write an example that initial-
izes a PPN, then reads and prints each field value, then changes each field 
value (by assigning to the field) and prints the result. Repeat this exercise, 
but  store  the  PPN  information  in  a  32-bit  unsigned  integer  and  use  bit  
manipulation operators (§25.5.4) to access the bits in the word. */

#include <iostream>
#include <bitset>

struct PPN {                     // R6000 Physical Page Number
    unsigned int PFN : 22 ;      // Page Frame Number
    int : 3 ;                    // **unused**
    unsigned int CCA : 3 ;       // Cache Coherency Algorithm
    bool nonreachable : 1 ;
    bool dirty : 1 ;
    bool valid : 1 ;
    bool global : 1 ;
};

void print_ppn(PPN& p) {
    std::cout << p.PFN << ' ' << p.CCA << ' ' << p.nonreachable << ' ' // 3 bits unused
              << p.dirty << ' ' << p.valid << ' ' << p.global << '\n';
}


struct IPPN {
    // std::bitset<32> ippn = 0;
    unsigned int ippn = 0;
    
    // when ippn is a bitset
    // unsigned int get_pfn() {
    //     return ((ippn >> 10) & std::bitset<32>(0x3fffff)).to_ulong();
    // }

    unsigned int get_pfn() {
        return (ippn >> 10) & 0x3fffff;
    }
    
    unsigned int get_cca() {
        return (ippn >> 4) & 0x7;
    }

    unsigned int get_nonreachable() {
        return (ippn >> 3) & 0x1;
    }

    unsigned int get_dirty() {
        return (ippn >> 2) & 0x1;
    }
    
    unsigned int get_valid() {
        return (ippn >> 1) & 0x1;
    }

    unsigned int get_global() {
        return ippn & 0x1;
    }

    void set_pfn(unsigned int vpfn) {
        ippn |= vpfn << 10;
    }

    void set_cca(unsigned int cca) {
        ippn |= cca << 4;
    }

    void set_nonreachable(bool b) {
        ippn |= b << 3;
    }

    void set_dirty(bool b) {
        ippn |= b << 2;
    }

    void set_valid(bool b) {
        ippn |= b << 1;
    }

    void set_global(bool b) {
        ippn |= b;
    }
};

void print_ippn(IPPN p) {
    std::cout << p.get_pfn() << ' ' << p.get_cca() << ' ' << p.get_nonreachable() << ' ' // 3 bits unused
            << p.get_dirty() << ' ' << p.get_valid() << ' ' << p.get_global() << '\n';
}

int main() {
    PPN p {100, 7, 1,0,1,1};

    // print_ppn(p);

    p.PFN = 20;
    p.CCA = 1;
    p.nonreachable = 0;
    p.dirty = 1;
    p.valid = 0;
    p.global = 0;

    // print_ppn(p);

    // 100, <3 bits>, 7, 1,0,1,1
    unsigned int ippn = 0;
    
    IPPN ip;
    ip.set_pfn(100);
    ip.set_cca(7);
    ip.set_nonreachable(1);
    ip.set_dirty(0);
    ip.set_valid(1);
    ip.set_global(1);

    print_ippn(ip);
}