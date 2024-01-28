#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void encipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long * const k)
{
    static_assert(sizeof(long)==4,"size of long wrong for TEA");
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0;
    const unsigned long delta = 0x9E3779B9;
    for (unsigned long n = 32; n-- > 0; ) {
            y += (z<<4 ^ z>>5) + z^sum + k[sum&3];
            sum += delta;
            z += (y<<4 ^ y>>5) + y^sum + k[sum>>11 & 3];
    }
    w[0]=y;
    w[1]=z;
}

void decipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long * const k)
{ 
    static_assert(sizeof(long)==4,"size of long wrong for TEA");
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0xC6EF3720;
    const unsigned long delta = 0x9E3779B9;
    
    // sum = delta<<5, in general sum = delta * n
    for (unsigned long n = 32; n-- > 0; ) {
    z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
    sum -= delta;
    y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
    }
    w[0]=y;
    w[1]=z;
}

int main()           // sender
{
          const int nchar = 2*sizeof(long);      // 64 bits
          const int kchar = 2*nchar;                    // 128 bits
          string op;
          string key;
          string infile;
          string outfile;
          cout << "please enter input file name, output file name, and key:\n";
          cin >> infile >> outfile >> key;
          while (key.size()<kchar) key += '0';    // pad key
          ifstream inf(infile);
          ofstream outf(outfile);
          if (!inf || !outf) throw std::runtime_error("bad file name");
          
          const unsigned long* k =
                    reinterpret_cast<const unsigned long*>(key.data());
        
        //   encipher
        //   unsigned long outptr[2];
        //   char inbuf[nchar];
        //   unsigned long* inptr = reinterpret_cast<unsigned long*>(inbuf); 
        //   int count = 0;
        //   while (inf.get(inbuf[count])) {
        //             outf << hex;                   // use hexadecimal output
        //             if (++count == nchar) {
        //                       encipher(inptr,outptr,k);
        //                       // pad with leading zeros:
        //                       outf << setw(8) << setfill('0') << outptr[0] << ' '
        //                                 << setw(8) << setfill('0') << outptr[1] << ' ';
        //                       count = 0;
        //             }
        //   }
        //   if (count) {  // pad
        //             while(count != nchar) inbuf[count++] = '0'; 
        //             encipher(inptr,outptr,k);
        //             outf << outptr[0] << ' ' << outptr[1] << ' ';
        //   }

        // decipher
        unsigned long inptr[2];
        char outbuf[nchar+1];
        outbuf[nchar]=0;   // terminator
        unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
        inf.setf(ios_base::hex ,ios_base::basefield);    // use hexadecimal input
        while (inf>>inptr[0]>>inptr[1]) {
                decipher(inptr,outptr,k);
                outf<<outbuf;
        }
}