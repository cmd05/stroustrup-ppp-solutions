template<typename T>
class counted_ptr {
public:
	counted_ptr();
	counted_ptr(T& v);
	counted_ptr(const counted_ptr& arg);
	counted_ptr& operator=(counted_ptr& arg);

	~counted_ptr();

	T& operator*() const { return p; }
	T* operator->() { return p; }

	int get_count() const { return *count; }
private:
	T* p;
	int* count;
};

template<typename T>
counted_ptr<T>::counted_ptr(T& v) {
	p = new T{v};
	count = new int{1};
}

template<typename T>
counted_ptr<T>::counted_ptr(const counted_ptr<T>& arg) {
	count = arg.count;
	p = arg.p;
	(*count)++;
}

template<typename T>
counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr<T>& arg) {
	if(this == &arg) return *this;

	// old counted_ptr count reduces by 1
	(*count)--;
	if(*count == 0) this->~counted_ptr();

	count = arg.count;
	p = arg.p;
	(*count)++;	
	return *this;
}


template<typename T>
counted_ptr<T>::~counted_ptr<T>() {
	(*count)--;

	if(*count == 0) {
		delete p;
		delete count;
		count = nullptr;
	}
}