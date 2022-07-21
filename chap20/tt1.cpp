#include <iostream>

vector<double>& get_from_jill() {
	vector<double>* v = new vector<double>[100];
	// ...
	vector<double>& vref = *v; // 
}