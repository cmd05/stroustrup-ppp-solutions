#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_until_ss(const vector<string>& v, const string& quit)
{
    bool occured = false;

    for(string s : v) {
        if(s == quit) {
            if(occured) return;
            occured = true;
        }

        cout << s << "\n";
    }
}

int main() {
    vector<string> v = {"str", "cmd05", "hello", "str", "str"};
    print_until_ss(v, "str");
}