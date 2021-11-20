#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_until_ss(const vector<string>& v, const string& quit)
{
    int count = 0;

    for(string s : v) {
        if(s == quit) count++;
        if(count > 1) return;

        cout << s << "\n";
    }
}

int main() {
    vector<string> v = {"str", "cmd05", "hello", "str", "str"};
    print_until_ss(v, "str");
}