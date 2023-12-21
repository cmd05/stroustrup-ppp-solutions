/* Write  a  program  that  reads  characters  from  cin  into  an  array  that  you  
allocate on the free store. Read individual characters until an exclamation 
mark (!) is entered. Do not use a std::string. Do not worry about mem-
ory exhaustion */

#include <iostream>

char* append(char* s, const char c, int& sz) {
    sz = sz + 1;

    char* s2 = new char[sz];
    for(int i = 0; s[i]; i++) s2[i] = s[i];
    
    s2[sz-1] = c;
    s2[sz] = '\0';

    delete[] s;

    return s2;
}

int main() {
    // either pre-allocate an array of reasonable on the free
    // use a `Link` (doubly linked list mechanism). but that is not an array

    // or keep making new arrays on free store and deleting old ones
    
    char* s = nullptr;
    int sz = 1; // including zero-terminator
                // start with sz=1 (even though size of s is 0),
                // so that first call to append makes an array of size==2 i.e {char_to_append, '\0'}
                // saves us from conditional check for each call to append
    for(char c; std::cin >> c;) {
        if(c == '!') break;
        else s = append(s, c, sz);
        
        std::cout << s << '\n';
    }
}