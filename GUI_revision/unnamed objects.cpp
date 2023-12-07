#include <iostream>
#include <vector>
#include <math.h>

/* Manage both named and unnamed objects */
/* Keep named pointers but delete unnamed objects on heap */

template<typename T>
class Vector_Ref {
public:
    Vector_Ref() {}
    ~Vector_Ref() { for(T* t : owned) delete t; }
    
    void push_back(T*&& t) { vc.push_back(t); owned.push_back(t); } // rvalue objects on heap
    void push_back(T*& t) { vc.push_back((T*) t); } // named objects on heap (do not delete tnem)
    void push_back(T& t) { vc.push_back(&t); }

    T& operator[](int i) { return *vc[i]; }
    const T& operator[](int i) const { return *vc[i]; }

    int size() { return vc.size(); }

    void print_all(std::ostream& os) { for(T* t : vc) os << *t << '\t'; std::cout << '\n'; }
private:
    std::vector<T*> owned; // keeps track of unnamed objects
    std::vector<T*> vc; // holds all objects
};

template<typename Num>
bool is_prime(Num n) {
    for(int i = 2; i < sqrt(n) + 1; i++)
        if((n % i) == 0) return false;
    return true;
}

int main() {

    double* first = new double{sqrt(2)};

    {
        Vector_Ref<double> vr {};
        vr.push_back(first); // first will not be deleted

        constexpr int total_terms = 10;
        for(int x = 3, n = 0; n < (total_terms - 1); x += 2) {
            if(is_prime(x)) {
                vr.push_back(new double {sqrt(x)});
                n++;
            }
        }

        double end = -1;
        
        vr.push_back(end); 
        vr.print_all(std::cout);
    }

    std::cout << "value of first [after ~vr()]: " << *first; // first is still valid
}