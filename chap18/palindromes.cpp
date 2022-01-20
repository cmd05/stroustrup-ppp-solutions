#include <iostream>
#include <string>

int str_len(const char* p) { // 0 terminated
    int len = 0;
    // for(;*p; len++, p++);
    while(*p != 0) { len++; p++; }

    return len;
}

// std string
bool is_palindrome(const std::string& s) {
    int first = 0;
    int last = s.length() - 1;

    while(first < last) {
        if(s[first] != s[last]) return false;
        first++;
        last--;
    }

    return true;
}

// arrays
bool is_palindrome(const char s[], int sz) {
    int first = 0;
    int last = sz - 1;
    
    while(first < last) {
        if(s[first] != s[last]) return false;
        first++;
        last--;
    }

    return true;
}

// pointers

bool is_palindrome(const char* first, const char* last) {
    while(first < last) {
        if(*first != *last) return false;
        // first++;
        // last--;
        return is_palindrome(first + 1, last - 1);
    }

    return true;
}

std::istream& read_word(std::istream& is, char* s, int max) {
    is.width(max);
    is >> s;

    return is;
}

int main() {
    constexpr int max = 128;

    for(char s[max]; read_word(std::cin, s, max);) {
        std::cout << s << " is";
        if(!is_palindrome(&s[0], &s[str_len(s) - 1])) std::cout << " not";
        std::cout << " a palindrome\n";
    }
}