#include <iostream>

const char* findx(const char* s, const char* x) {
    for(; *s; s++) {
        if(*s == *x) { // first letter match
            bool is_match = true;
            const char* begin = s;

            for(const char* x2 = x; *x2; x2++, s++) {
                if(!*s || *x2 != *s) { // if src is over OR letters dont match
                    is_match = false; 
                    break;
                }
            }

            if(is_match) return begin;
        }
    }

    return nullptr;
}

int main() {
    const char msg[] = "Attachment is forbidden. Possession is forbidden." 
                      " Compassion, which I would define as unconditional lsove, "
                      "is essential to a Jedi's life. So you might say, that "
                      "we are encouraged to love!";
    const char search[] = "love";
    
    std::cout << findx(msg, search);
}