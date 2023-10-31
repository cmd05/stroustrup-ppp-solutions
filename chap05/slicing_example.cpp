#include <stdexcept>
#include <iostream>

class my_exception : public std::exception {
  virtual const char *what() const throw() {
    return "Hello, world!";
  }
};

int main() {
  try {
    throw my_exception();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}

// without reference: std::exception
// with reference: Hello, world!