#include <iostream>

// 0 std : 1 local
#define __TEST 1

#if __TEST == 1
	#include <list>
	#define list_int std::list<int>
#else
	#include "list.h"
	#define list_int list<int>
#endif

struct X { int a = 10; X(int) {} };
std::ostream& operator<<(std::ostream& os, const X& x) { std::cout << "X\n"; return os; }

void print_it(std::initializer_list<list_int::iterator> lst) {
	for(auto x : lst)
		std::cout << &(*x) << "\t";
}

void pt_li(list_int ls) {
	for(auto x : ls)
		std::cout << x << '\t';
}

int main() {
	list_int l {1,2,3,4};
	l.push_front(20);
	l.push_back(5);
	l.pop_front();

	l.push_front(32);
	l.resize(20);
	auto t = l.begin();
	t++;
	l.insert(t, 432);
	
	pt_li(l);
}