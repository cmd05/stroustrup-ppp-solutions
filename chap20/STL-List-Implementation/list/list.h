#include <memory>
#include <iterator>
#include <limits>

/**
 * A custom implementation of the standard library list
 *
 * DEFINITIONS:
 *	- pre: node before first element
 *	- sent: node after last element
 *	- head: first element of list
 *	- tail: last element of list 
 *	- node: node refers to list_node
 *
 * NOTES:
 *	- An invalid list will be in the form {nullptr, nullptr, 0} 
 *	 (check before destroying or dereferencing)
 *	- An empty list will in the form {sent, sent, 0}
 *	- A non-empty list will be in the form {head, tail, n} 
 *
 *	- For an empty list list.begin() == list.end()
 *	- pre and sent are not stored explicitly by list, and they do not 
 *	  contain a valid value. They must be used only for checking the bounds
 *	  of the list.
 *
 *	- the list provides a custom resize_uninitialized() which allocates uninitialized storage
 *	  for list nodes
 */ 
template<typename T, typename A = std::allocator<T>>
class list {
private:
	/// Private Typedefs
	struct list_node;
public:
	/// Public Typedefs
	using size_type = std::size_t;
	using value_type = T;
	class iterator; // bidirectional iterator
	class reverse_iterator;
	using node_allocator = typename A::template rebind<list_node>::other;

	/// CTORs
	list();
	list(std::initializer_list<T> lst);
	list(iterator begin, iterator end);
	explicit list(size_type sz);
	void assign(iterator first, iterator last);

	/// Copy and Move Semantics, DTOR
	list(const list& other);
	list& operator=(const list& other);
	list(list&& other);
	list& operator=(list&& other);
	~list();

	/// Tterators
	iterator begin() const;
	iterator tail() const;
	iterator end() const;
	reverse_iterator rbegin() const;
	reverse_iterator rend() const;

	/// Element Access
	T& front() const;
	T& back() const;

	/// Capacity
	bool empty() const;
	size_type size() const;
	size_type max_size() const;
	
	/// Modifiers
	void clear();
	iterator insert(iterator pos, const T& val);
	iterator erase(iterator pos);
	void push_back(const T& val);
	void pop_back();
	void push_front(const T& val);
	void pop_front();
	void resize_uninitialized(size_type count);
	void resize(size_type count, T val = T());
	void swap(list& other);

	/// Operations
	template<class Compare = std::less<>>
	void sort(Compare cmp = {});
		
	void merge(list& other);
	void reverse();
private:
	/// Private Modifiers
	void alloc_empty_list();
	void delete_node(iterator pos);
	void invalidate_list(list& ls);
	list_node* get_node();
	list_node* get_node(list_node lnode);
	iterator insert(iterator pos, list_node* node);
	void push_back(list_node* node);

	/// Properties
	list_node* _head;
	list_node* _tail;
	size_type _size;
	node_allocator alloc;
};

/// List Node
template<typename T, typename A>
struct list<T,A>::list_node {
	friend class list;

	T _val;
	list_node* _prev;
	list_node* _next;
public:
	list_node(): _prev{nullptr}, _next{nullptr}, _val{T()} {}
	// list_node() {}

	list_node(T v): _val{v} {}
	list_node(T v, list_node* p, list_node* s): _val{v}, _prev{p}, _next{s} {}
	list_node(list_node* p, list_node* s): _prev{p}, _next{s} {}
	// list_node(list_node* p, T v): _val{v}, _prev{p} {}
	// list_node(T v, list_node* s): _val{v}, _next{s} {}
};

/// List Iterators
template<typename T, typename A>
class list<T,A>::iterator {
	friend class list;
	list_node* node;
public:
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;

	iterator();
	iterator(list_node* p): node{p} {}

	iterator& operator++() { node = node->_next; return *this; }
	iterator operator++(int) { iterator tmp {node}; node = node->_next; return tmp; }
	iterator& operator--() { node = node->_prev; return *this; }
	iterator operator--(int) { iterator tmp {node}; node = node->_prev; return tmp; }

	T& operator*() { return node->_val; }
	T* operator->() { return &(node->_val); }

	bool operator==(const iterator& b) const { return node==b.node; }
	bool operator!=(const iterator& b) const { return node!=b.node; }
};

template<typename T, typename A>
class list<T,A>::reverse_iterator {
	list_node* node;
public:
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;

	reverse_iterator();
	reverse_iterator(list_node* p): node{p} {}

	reverse_iterator& operator++() { node = node->prev; return *this; }
	reverse_iterator operator++(int) { reverse_iterator tmp {node}; node = node->_prev; return tmp; }
	reverse_iterator& operator--() { node = node->_next; return *this; }
	reverse_iterator operator--(int) { reverse_iterator tmp {node}; node = node->_next; return tmp; }

	T& operator*() { return node->_val; }
	T* operator->() { return &(node->_val); }

	bool operator==(const reverse_iterator& b) const { return node==b.node; }
	bool operator!=(const reverse_iterator& b) const { return node!=b.node; }
};

/// CTORs
template<typename T, typename A>
list<T,A>::list() {
	alloc_empty_list();
}

template<typename T, typename A>
list<T,A>::list(std::initializer_list<T> lst) {
	alloc_empty_list();
	std::copy(lst.begin(), lst.end(), std::back_inserter(*this));
}

template<typename T, typename A>
list<T,A>::list(iterator begin, iterator end) {
	alloc_empty_list();
	std::copy(begin, end, std::back_inserter(*this));
}

template<typename T, typename A>
list<T,A>::list(size_type sz) {
	alloc_empty_list();
	for(size_type i = 0; i < sz; i++)
		push_back(T());
}

template<typename T, typename A>
void list<T,A>::assign(iterator first, iterator last) {
	iterator current_it = begin();

	for(; current_it != end() && first != last; current_it++, first++)
		*current_it = *first;
	if(current_it == end())
		for(; first != last; first++)
			push_back(*first);
	else
		for(; current_it != end(); current_it++)
			erase(current_it);
}

/// Copy and Move Semantics, DTOR
template<typename T, typename A>
list<T,A>::list(const list<T,A>& other) {
	alloc_empty_list();
	std::copy(other.begin(), other.end(), std::back_inserter(*this));
}

template<typename T, typename A>
list<T,A>& list<T,A>::operator=(const list<T,A>& other) {
	alloc_empty_list();
	if(this != &other)
		assign(other.begin(), other.end());
	
	return *this;
}

template<typename T, typename A>
list<T,A>::list(list<T,A>&& other):
	_head{other._head}, _tail{other._tail}, _size{other._size} {	
	invalidate_list(other);
}

template<typename T, typename A>
list<T,A>& list<T,A>::operator=(list<T,A>&& other) {
	~list();

	_head = other._head;
	_tail = other._tail;
	_size = other._size;

	invalidate_list(other);
}

template<typename T, typename A>
list<T,A>::~list() {
	// an invalid list will contain nullptr as head and tail
	// do not attempt to destroy such a list
	if(!_head || !_tail) return;

	iterator pre = iterator{_head->_prev};
	iterator sent = iterator{_tail->_next};

	clear();

	delete_node(pre);
	delete_node(sent);
}

/// Tterators
template<typename T, typename A>
typename list<T,A>::iterator list<T,A>::begin() const {
	return iterator{_head};
}

template<typename T, typename A>
typename list<T,A>::iterator list<T,A>::tail() const {
	return iterator{_tail};
}

template<typename T, typename A>
typename list<T,A>::iterator list<T,A>::end() const {
	return iterator{_tail->_next};
}

template<typename T, typename A>
typename list<T,A>::reverse_iterator list<T,A>::rbegin() const {
	return reverse_iterator{_tail};
}

template<typename T, typename A>
typename list<T,A>::reverse_iterator list<T,A>::rend() const {
	return reverse_iterator{_head->_prev};
}

/// Element Access
template<typename T, typename A>
T& list<T,A>::front() const {
	return _head->_val;
}

template<typename T, typename A>
T& list<T,A>::back() const {
	return _tail->_val;
}

/// Capacity
template<typename T, typename A>
bool list<T,A>::empty() const {
	return _size == 0;
}

template<typename T, typename A>
typename list<T,A>::size_type list<T,A>::size() const {
	return _size;
}

template<typename T, typename A>
typename list<T,A>::size_type list<T,A>::max_size() const {
	return std::numeric_limits<size_type>::max();
}

/// Private Modifiers
template<typename T, typename A>
void list<T,A>::alloc_empty_list() {
	list_node* sent = get_node();
	list_node* pre = get_node();

	pre->_prev = pre;
	pre->_next = sent;

	sent->_prev = pre;
	sent->_next = sent;

	_head = sent;
	_tail = sent;
	_size = 0;
}

// Invalidate a list to prevent overwriting of elements
// by destructor or manually.
// Useful for shallow copying one list to another
template<typename T, typename A>
void list<T,A>::invalidate_list(list<T,A>& ls) {
	ls._size = 0;
	ls._head = nullptr;
	ls._tail = nullptr;
}

template<typename T, typename A>
typename list<T,A>::list_node* list<T,A>::get_node() {
	return alloc.allocate(1);
}

template<typename T, typename A>
typename list<T,A>::list_node* list<T,A>::get_node(list_node lnode) {
	list_node* tmp = alloc.allocate(1);
	alloc.construct(tmp, lnode);
	return tmp;
}

template<typename T, typename A>
void list<T,A>::delete_node(iterator pos) {
	list_node* p = pos.node;
	alloc.destroy(p);
	alloc.deallocate(p, 1);
}

template<typename T, typename A>
typename list<T,A>::iterator list<T,A>::insert(iterator pos, list_node* new_node) {
	list_node* pos_node = pos.node;
	// set new head and tail
	if(pos == begin()) _head = new_node;
	if(pos == end()) _tail = new_node;

	// set next pointer of new node
	new_node->_next = pos_node;
	
	// set prev pointer of new node
	new_node->_prev = pos_node->_prev;

	// set next pointer of insert_pos->_prev
	pos_node->_prev->_next = new_node;

	// set prev pointer of insert_pos
	pos_node->_prev = new_node;
	
	++_size;
	return new_node;
}

template<typename T, typename A>
void list<T,A>::push_back(list_node* node) {
	insert(end(), node);
}

/// Public Modifiers
template<typename T, typename A>
typename list<T,A>::iterator list<T,A>::insert(iterator pos, const T& val) {
	return insert(pos, get_node(val));
}

template<typename T, typename A>
typename list<T,A>::iterator list<T,A>::erase(iterator pos) {
	list_node* pos_node = pos.node;
	iterator next_pos {pos_node->_next};

	// reset node links
	pos_node->_prev->_next = pos_node->_next;
	pos_node->_next->_prev = pos_node->_prev;
	
	// set new head and tail
	if(pos == begin()) _head = _head->_next;
	if(pos == tail()) 
		if(_size == 1) _tail = _head;
		else _tail = _tail->_prev;

	delete_node(pos);
	--_size;

	return next_pos;
}

template<typename T, typename A>
void list<T,A>::clear() {
	while(begin() != end()) {
		list_node* tmp = _head->_next;
		erase(_head);
		_head = tmp;
	}

	_size = 0;
}

template<typename T, typename A>
void list<T,A>::push_back(const T& val) {
	insert(end(), get_node(val));
}

template<typename T, typename A>
void list<T,A>::push_front(const T& val) {
	insert(begin(), val);
}

template<typename T, typename A>
void list<T,A>::pop_back() {
	erase(tail());
}

template<typename T, typename A>
void list<T,A>::pop_front() {
	erase(begin());
}

template<typename T, typename A>
void list<T,A>::resize_uninitialized(size_type count) {
	size_type diff = count - _size;

	for(; diff > 0; diff--) push_back(get_node());
	for(; diff < 0; diff++) pop_back();
}

template<typename T, typename A>
void list<T,A>::resize(size_type count, T val) {
	size_type diff = count - _size;

	for(; diff > 0; diff--) push_back(get_node(val));
	for(; diff < 0; diff++) pop_back();
}

template<typename T, typename A>
void list<T,A>::swap(list<T,A>& other) {
	std::swap(other._head, _head);
	std::swap(other._tail, _tail);
	std::swap(other._size, _size);
	std::swap(other.alloc, alloc);
}

/// Operations
template<typename T, typename A>
template<class Compare>
void list<T,A>::sort(Compare cmp) {
	// TODO
}

template<typename T, typename A>
void list<T,A>::merge(list<T,A>& other) {
	if(this == &other) return;

	// concatenate other to current list
	_tail->_next = other._head;
	other._head->_prev = _tail;
	_tail = other._tail;
	_size += other._size;

	// sort combined list
	sort();

	// reset other list.
	// other will still be valid
	other._head = nullptr;
	other._tail = nullptr;
	other._size = 0;

	other.alloc_empty_list();
}

template<typename T, typename A>
void list<T,A>::reverse() {
	iterator p1 = begin();
	iterator p2 = tail();
	size_type mid = int(_size / 2) + 1;

	for(size_type i = 0; i != mid; i++, p1++, p2--)
		*p1 = *p2;
}

/// Non Member Functions
template<typename T, typename A>
bool operator==(const list<T,A>& first, const list<T,A>& second) {
	if(first.size() != second.size()) return false;

	typename list<T,A>::iterator p1 = first.begin();
	typename list<T,A>::iterator p2 = second.begin();
	for(; p1 != first.end(); p1++, p2++)
		if(*p1 != *p2) return false;
	
	return true;
}

template<typename T, typename A>
bool operator!=(const list<T,A>& first, const list<T,A>& second) {
	return !(first == second);
}