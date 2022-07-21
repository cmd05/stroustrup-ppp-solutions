template<typename T>
class list {
public:
	class Link;
	using size_type = unsigned long;
	using value_type = T;
	class iterator;
	class const_iterator;

	iterator begin() const;
	iterator end() const;
	iterator insert();
	iterator erase();

	void push_back(const T& v);
	void push_front(const T& v);
	void pop_front();
	void pop_back();

	T& front();
	T& back();
private:
	iterator head;
	iterator sentinel;
}

template<typename T>
class list<T>::Link {
	T val;
	Link* prev;
	Link* succ;
}

template<typename T>
class list<T>::iterator {
	Link<T>* curr;
public:
	iterator(Link<T>* p): curr{p} {}

	iterator& operator++() { curr = curr->succ; return *this; }
	iterator& operator--() { curr = curr->prev; return *this; }
	T& operator*() { return curr->val; }

	bool operator==(const iterator& b) const { return curr==b.curr; }
	bool operator!=(const iterator& b) const { return curr!=b.curr; }
}

template<typename C>
using iterator = typename C::iterator;

template<typename C>
using value_type = typename C::value_type;

template<typename T>
iterator list<T>::begin() const { return head; }

template<typename T>
iterator list<T>::end() const { return sentinel; }

template<typename T>
T& list<T>::front() const { return head->curr->val; }

template<typename T>
T& list<T>::back() const { return sentinel->curr->val; }