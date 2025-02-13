#ifndef DSA_HASHMAP_HPP
#define DSA_HASHMAP_HPP

#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <stdexcept>

namespace dsa {

template<typename Key, typename Value>
class HashMap {
public:
    HashMap(std::size_t buckets = 10);
    ~HashMap() = default;

    void put(const Key& key, const Value& value);
    bool get(const Key& key, Value& value) const;
    void remove(const Key& key);
private:
    std::vector<std::list<std::pair<Key, Value>>> table_;
    std::size_t buckets_;
    std::size_t hash(const Key& key) const;
};

template<typename Key, typename Value>
HashMap<Key, Value>::HashMap(std::size_t buckets) : buckets_(buckets) {
    table_.resize(buckets_);
}

template<typename Key, typename Value>
std::size_t HashMap<Key, Value>::hash(const Key& key) const {
    return std::hash<Key>{}(key) % buckets_;
}

template<typename Key, typename Value>
void HashMap<Key, Value>::put(const Key& key, const Value& value) {
    std::size_t index = hash(key);
    for (auto& pair : table_[index]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    table_[index].push_back({key, value});
}

template<typename Key, typename Value>
bool HashMap<Key, Value>::get(const Key& key, Value& value) const {
    std::size_t index = hash(key);
    for (const auto& pair : table_[index]) {
        if (pair.first == key) {
            value = pair.second;
            return true;
        }
    }
    return false;
}

template<typename Key, typename Value>
void HashMap<Key, Value>::remove(const Key& key) {
    std::size_t index = hash(key);
    auto& cell = table_[index];
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            cell.erase(it);
            return;
        }
    }
}

} // namespace dsa

#endif // DSA_HASHMAP_HPP
