#include <cassert>
#include "dsa/Stack.hpp"

int main() {
    dsa::Stack<int> stack;
    stack.push(5);
    stack.push(10);
    assert(stack.top() == 10);
    stack.pop();
    assert(stack.top() == 5);
    return 0;
}
