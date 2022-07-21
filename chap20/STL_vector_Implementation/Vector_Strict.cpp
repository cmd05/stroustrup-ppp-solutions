#include "Vector_Strict.h"

template<typename T> 
T& Vector_Strict::operator[](size_type i) {
	if(i < 0 || i >= this->size()) throw Range_error(i);
	return vector<T>::operator[](i);
}

template<typename T> 
const T& Vector_Strict::operator[](size_type i) const {
	if(i < 0 || i >= this->size()) throw Range_error(i);
	return vector<T>::operator[](i);
}