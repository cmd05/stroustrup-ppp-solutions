#include <iostream>
using namespace std;

void f(int i, double fpd)
{
          char c = i;      // yes: chars really are very small integers
          short s = i;        // beware: an int may not fit in a short int
          i = i+1;            // what if i was the largest int?
          long lg = i*i;     // beware: a long may not be any larger than an int
          float fps = fpd;   // beware: a large double may not fit in a float
          i = fpd;          // truncates: e.g., 5.7 – > 5
          fps = i;         // you can lose precision (for very large int values)

          cout << int(c) << ' ' << s << ' ' << i << ' ' << lg << ' ' << fps;
}
void g()
{
          char ch = 0;
          for (int i = 0; i<500; ++i) 
                    cout << int(ch++) << '\t';
}

int main() {
    f(2100000006, 2781.452);
    // g();
}