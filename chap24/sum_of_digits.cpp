#include <iostream>

int main() {
    int x = 6780650;
    int sum = 0;

    while(x != 0) {
        sum += x%10;
        x /= 10;    
    }

    std::cout << sum;
}