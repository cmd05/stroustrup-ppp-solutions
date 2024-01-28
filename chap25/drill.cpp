#include <iostream>
using namespace std;

void pt(std::initializer_list<short unsigned int> l) {
    for(short unsigned int x : l) {
        std::cout << dec << x << '\t' << hex << x << '\n';
    }
}

int main() {
    // int v = 1; for (int i = 0; i<sizeof(v)*8; ++i) { cout << v << ' '; v <<=1; }
    // unsigned int v = 1; for (int i = 0; i<sizeof(v)*8; ++i) { cout << v << ' '; v <<=1; }

    short unsigned int x1 = 0xffff;

    short unsigned int x2 = 0x0001;
    short unsigned int x3 = 0x8000;
    
    short unsigned int x4 = 0x00ff;
    short unsigned int x5 = 0xff00;
    
    short unsigned int x6 = 0x5555;
    short unsigned int x7 = 0xaaaa;

    pt({x1,x2,x3,x4,x5,x6,x7});

    std::cout << "\n";

    short unsigned int y1 = ~0;
    short unsigned int y2 = y1 & 1;
    short unsigned int y3 = ~(y1 >> 1);
    short unsigned int y4 = y1 >> 12;
    short unsigned int y5 = y1 << 12;
    // short unsigned int y6 = y1 << 12;
    // short unsigned int y7 = y1 << 12;

    // 1111 1111  1111 1111
    // 0000 0000  0000 0001
    // 1000 0000  0000 0000

    pt({y1,y2,y3});
}