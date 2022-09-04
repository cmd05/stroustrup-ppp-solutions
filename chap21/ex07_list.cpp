#include <iostream>
#include <list>

template<typename T>
using list_iterator = typename std::list<T>::iterator;

template<typename T>
using lsize_type = typename std::list<T>::size_type;

// list arranged in ascending order
// iend is a part of lst but not oend
template<typename T>
list_iterator<T> search_lower(std::list<T>& lst, list_iterator<T> ibegin, list_iterator<T> iend,
                              lsize_type<T> sz, T val, list_iterator<T> obegin, list_iterator<T> oend) {
    if(sz == 0) return oend;

    lsize_type<T> new_sz = (sz / 2);
    if(sz % 2 == 0) --new_sz;

    list_iterator<T> imid = std::next(ibegin, new_sz);

    if(sz % 2 == 0) ++new_sz;

    if(*imid >= val) {
        list_iterator<T> tmp = imid;
        --tmp;
        if(imid == obegin || *tmp < val)
            return imid;
        else
            return search_lower(lst, ibegin, --imid, new_sz, val, obegin, oend);
    }
    else if(*imid < val)
        return search_lower(lst, ++imid, iend, new_sz, val, obegin, oend);
    else
        return search_lower(lst, ibegin, --imid, new_sz, val, obegin, oend);
}

template<typename T>
list_iterator<T> lower_bound(std::list<T>& lst, list_iterator<T> ibegin,
                             list_iterator<T> iend, lsize_type<T> sz, T val) {
    list_iterator<T> tmp = iend;
    return search_lower(lst, ibegin, --tmp, sz, val, ibegin, iend);
}

int main() {
    std::list<double> l {0,1,2,3,4,5,6,7,8,9,10,11};
    std::cout << *lower_bound(l, l.begin(), l.end(), l.size(), 6.9);
}