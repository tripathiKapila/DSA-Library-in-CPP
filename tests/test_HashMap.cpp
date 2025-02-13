#include <cassert>
#include <string>
#include "dsa/HashMap.hpp"

int main() {
    dsa::HashMap<std::string, int> hashmap;
    hashmap.put("key1", 100);
    int value;
    bool found = hashmap.get("key1", value);
    assert(found && value == 100);
    hashmap.remove("key1");
    found = hashmap.get("key1", value);
    assert(!found);
    return 0;
}
