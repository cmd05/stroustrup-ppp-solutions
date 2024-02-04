#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <concepts>

struct Shape {
    virtual void draw() { std::cout << "Shape::draw()\n"; }
};

struct Circle : public Shape {
    void draw() override { std::cout << "Circle::draw()\n"; }
    Circle(int a): r{a} {}
    int r;
};

struct Rectangle : public Shape {
    void draw() override { std::cout << "Rectangle::draw()\n"; }
    Rectangle(int c, int d): a{c}, b{d} {}
    int a, b;
};

template<typename In>
    // requires Input_iterator
    // Container<Shape>
void draw_all(In b, In e) {
    std::for_each(b, e, std::mem_fn(&Shape::draw)); // this line combines all four fundamental
                                                    // programming paradigms in C++
}


// using concepts

// concept for a C++STL Container
template <class ContainerType> 
concept Container = requires(ContainerType a, const ContainerType b) 
{
    requires std::regular<ContainerType>;
    requires std::swappable<ContainerType>;
    requires std::destructible<typename ContainerType::value_type>;
    requires std::same_as<typename ContainerType::reference, typename ContainerType::value_type &>;
    requires std::same_as<typename ContainerType::const_reference, const typename ContainerType::value_type &>;
    requires std::forward_iterator<typename ContainerType::iterator>;
    requires std::forward_iterator<typename ContainerType::const_iterator>;
    requires std::signed_integral<typename ContainerType::difference_type>;
    requires std::same_as<typename ContainerType::difference_type, typename std::iterator_traits<typename
ContainerType::iterator>::difference_type>;
    requires std::same_as<typename ContainerType::difference_type, typename std::iterator_traits<typename
ContainerType::const_iterator>::difference_type>;
    { a.begin() } -> std::same_as<typename ContainerType::iterator>;
    { a.end() } -> std::same_as<typename ContainerType::iterator>;
    { b.begin() } -> std::same_as<typename ContainerType::const_iterator>;
    { b.end() } -> std::same_as<typename ContainerType::const_iterator>;
    { a.cbegin() } -> std::same_as<typename ContainerType::const_iterator>;
    { a.cend() } -> std::same_as<typename ContainerType::const_iterator>;
    { a.size() } -> std::same_as<typename ContainerType::size_type>;
    { a.max_size() } -> std::same_as<typename ContainerType::size_type>;
    { a.empty() } -> std::same_as<bool>;
};

// g++ paradigms.cpp -std=c++20; ./a.exe
template<typename Container>
void draw_all(Container& c) {
    for(auto& p : c) p->draw();
}

int main() {
    std::vector<Shape*> v;
    v.push_back(new Circle{5});
    v.push_back(new Circle{10});
    v.push_back(new Shape{});
    v.push_back(new Rectangle{2,2});
    v.push_back(new Rectangle{5,4});
    // draw_all(v.begin(), v.end());

    draw_all(v);
}