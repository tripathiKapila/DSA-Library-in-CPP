#include <cassert>
#include "dsa/Array.hpp"

int main() {
    dsa::DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    assert(arr.size() == 3);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    arr.pop_back();
    assert(arr.size() == 2);
    return 0;
}
