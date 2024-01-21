#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <list>

template<typename It, typename Elem>
// `It` must be an input iterator
// Elem must be equality comparable
It find(It first, It last, const Elem& val) {
    while(first != last && *first != val) ++first;
    return first;
}

template<typename Num>
// Num supports modulus operator
bool odd(Num x) { return x % 2; }

template<typename It, typename Pred>
// It must be an input iterator
// Predicate<Pred, Value_type<It>>()
It find_if(It first, It last, Pred pred) {
    while(first != last && !pred(*first)) ++first;
    return first;
}

class Larger_than {
    int num;
public:
    Larger_than(int n): num{n} {}
    bool operator()(int n) const { return n > num; } // operator() aka function call operator
};

struct Record {
    std::string name;
    char addr[24];
};

struct cmp_by_name{
    bool operator()(const Record& a, const Record& b) const {
        return a.name < b.name;
    }
};

struct cmp_by_addr {
    bool operator()(const Record& a, const Record& b) const { // function call [operator()] is inlined
                                                              // but a normal function is not
        return strncmp(a.addr, b.addr, 24) < 0;
    }
};

template<typename It, typename T>
// note: accumulator `init` maybe of different type than of *It
// Ex: `init` is (long double) while `*first` is (int)
T accumulate(It first, It last, T init) {
    while(first != last) {
        init += *first;
        ++first;
    }

    return init;
}

template<typename It, typename T, typename BinOp>
// requires Input_iterator<It>()
// Number<T>() satisfying BinOp
// Binary_operator<BinOp, Value_type<It>, T>()
T accumulate(It first, It last, T init, BinOp op) {
    while(first != last) {
        init = op(init, *first);
        ++first;
    }

    return init;
}

template<typename It, typename It2, typename T, typename BinOp, typename BinOp2>
T inner_product(It first, It last, It2 first_2, T init, BinOp op, BinOp op2) {
    while(first != last) {
        init = op(init, op2(*first, *first_2));

        ++first;
        ++first_2;
    }

    return init;
}

template<typename In, typename Out>
Out copy(In first, In last, Out res) {
    for(; first != last; ++first, ++res)
        *res = *first;

    return res; // one past last element of destination sequence
}

template<typename It, typename It2, typename Pred>
It2 copy_if(It first, It last, It2 res, Pred p) {
    for(; first != last; ++first, ++res)
        if(p(*first)) 
            *res = *first;

    return res;
}

int main() {
    std::vector v {4,2,3};
    // std::cout << *find_if(v.begin(), v.end(), odd<int>) << ' ';
    // std::cout << *find_if(v.begin(), v.end(), [](int x){ return !(x % 2); }) << ' ';
    
    std::vector v2 {57,14,64,32};

    // std::cout << *find_if(v2.begin(), v2.end(), Larger_than{60});
    std::vector<Record> v3 {{"abc", "def"}, {"hello", "world"}, {"hdd", "sxd"}};

    std::sort(v3.begin(), v3.end(), [](const Record& a, const Record& b) { return strncmp(a.addr, b.addr, 24) < 0; });

    int x = 5;
    x = accumulate(v.begin(), v.end(), x);
    // std::cout << x;

    std::map<std::string, int> m {{"b", 12}, {"g", 5}, {"a", 12}, {"c", 13}};

    // for(const auto& p : m)
    //     std::cout << p.first << p.second << ' ';

    // // same as
    // for(auto p = m.begin(); p != m.end(); p++)
    //     std::cout << (*p).first << (*p).second << ' ';

    std::vector vc {1,2,3,4};
    std::list lc2 {4,5,6,7,8};

    if(lc2.size() < vc.size())
        throw std::runtime_error("cannot copy vector");
    
    std::copy(vc.begin(), vc.end(), lc2.end());
}