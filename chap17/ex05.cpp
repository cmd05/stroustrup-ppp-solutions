#include <iostream>

// bool check_ahead(const char* s, const char* x, int pos) {
//     for(int i = 0; x[i]; i++) 
//         if(!s[pos+i] || x[i] != s[pos+i]) return false; // if end of subject or character not matching

//     return true;
// }

char* findx(const char* s, const char* x) {
    for(int i = 0; s[i]; i++) {
        if(s[i] == x[0]) { // first char occurence 
            bool is_match = true; // assume true match  

            for(int j = 0; x[j]; j++) // check all chars of x
                if(!s[i+j] || x[j] != s[i+j]) {  // if end of subject or character not matching
                    is_match = false;
                    break;
                }
                
            if(is_match) return const_cast<char*>(&s[i]);
        }
    }

    return nullptr;
}

int main() {
    char s[] = "Keep it simple, yet no simpler";
    char x[] = "simple";
    char y[] = "simplers";

    std::cout << findx(s, x) << "\n";
    std::cout << (!findx(s, y) ? "no occurences" : "");
}