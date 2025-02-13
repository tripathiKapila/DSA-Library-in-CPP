#include <iostream>
#include "dsa/Array.hpp"
#include "dsa/LinkedList.hpp"

int main() {
    std::cout << "Example Basic: Using DynamicArray and LinkedList\n";
    
    dsa::DynamicArray<int> arr;
    for (int i = 0; i < 5; i++) {
        arr.push_back(i * 10);
    }
    
    std::cout << "DynamicArray: ";
    for (std::size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    dsa::LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    std::cout << "LinkedList: ";
    while (!list.empty()) {
        std::cout << list.front() << " ";
        list.pop_front();
    }
    std::cout << "\n";
    
    return 0;
}
