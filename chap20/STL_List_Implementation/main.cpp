#include <iostream>
#include "list.h"

int main() {
	void f()
	{
		list<int> lst; for (int x; cin >> x; ) lst.push_front(x);
		list<int>::iterator p = high(lst.begin(), lst.end());
		cout << "the highest value was " << *p << '\n';
	}
}