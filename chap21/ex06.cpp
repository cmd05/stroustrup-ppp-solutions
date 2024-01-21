#include <set>
#include <iostream>
#include <string>

struct Fruit {
	std::string name;
	int price;
};

bool operator<(Fruit a, Fruit b) {
	return a.name < b.name;
}

bool operator>(Fruit a, Fruit b) {
	return a.name > b.name;
}

bool operator==(Fruit a, Fruit b) {
	return a.name == b.name;
}

class Fruit_comparison {
public:
	bool operator()(Fruit* a, Fruit* b) const {
		return a->name < b->name;
	}
};

template<typename C>
void fill_set(C& st) {
	st.insert({"Apple", 1});
	st.insert({"Orange", 1});
	st.insert({"Banana", 1});
	st.insert({"Kiwi", 1});
	st.insert({"Plum", 1});
	st.insert({"Guava", 1});
}

template<typename C>
void fill_pset(C& st) {
	st.insert(new Fruit{"Apple", 1});
	st.insert(new Fruit{"Orange", 1});
	st.insert(new Fruit{"Banana", 1});
	st.insert(new Fruit{"Kiwi", 1});
	st.insert(new Fruit{"Plum", 1});
	st.insert(new Fruit{"Guava", 1});
}

int main() {
	std::set<Fruit> s_ft;
	fill_set(s_ft);

	for(auto v : s_ft)
		std::cout << v.name << "\n";

	std::cout << "\n";
	std::set<Fruit*, Fruit_comparison> s_pft;
	fill_pset(s_pft);

	for(auto v : s_pft)
		std::cout << v->name << "\n";
}