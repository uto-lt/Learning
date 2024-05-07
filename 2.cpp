#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr1(new int(42));
    std::unique_ptr<int> ptr2;

    std::cout << "ptr1: " << (ptr1 ? "not null" : "null") << std::endl; // ptr1: not null
    std::cout << "ptr2: " << (ptr2 ? "not null" : "null") << std::endl; // ptr2: null

    ptr2 = std::move(ptr1);

    std::cout << "ptr1: " << (ptr1 ? "not null" : "null") << std::endl; // ptr1: null
    std::cout << "ptr2: " << (ptr2 ? "not null" : "null") << std::endl; // ptr2: not null

    return 0;
}