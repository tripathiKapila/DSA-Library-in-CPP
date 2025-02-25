/**
 * @file HashMap.hpp
 * @brief Declares a hash map using separate chaining.
 */

 #ifndef DSA_HASHMAP_HPP
 #define DSA_HASHMAP_HPP
 
 #include <vector>
 #include <list>
 #include <utility>
 #include <functional>
 #include <stdexcept>
 
 namespace dsa {
 
 /**
  * @class HashMap
  * @brief A hash map implementation.
  *
  * Uses separate chaining for collision resolution and supports dynamic rehashing.
  *
  * @tparam Key Type of keys.
  * @tparam Value Type of values.
  */
 template<typename Key, typename Value>
 class HashMap {
 public:
     /**
      * @brief Constructs a HashMap with a specified number of buckets.
      * @param buckets Initial number of buckets.
      */
     HashMap(std::size_t buckets = 10);
 
     /// Destructor.
     ~HashMap() = default;
 
     /**
      * @brief Inserts or updates a key-value pair.
      *
      * @param key Key to insert.
      * @param value Value associated with the key.
      */
     void put(const Key& key, const Value& value);
 
     /**
      * @brief Retrieves the value associated with a key.
      *
      * @param key Key to search for.
      * @param value Reference to store the found value.
      * @return True if key is found, false otherwise.
      */
     bool get(const Key& key, Value& value) const;
 
     /**
      * @brief Removes a key-value pair.
      *
      * @param key Key to remove.
      */
     void remove(const Key& key);
 
 private:
     std::vector<std::list<std::pair<Key, Value>>> table_; ///< Underlying table.
     std::size_t buckets_;  ///< Number of buckets.
     std::size_t size_;     ///< Number of elements.
     const float maxLoadFactor_ = 0.75f; ///< Maximum allowed load factor.
 
     /**
      * @brief Computes the hash for a key.
      * @param key Key to hash.
      * @return Bucket index.
      */
     std::size_t hash(const Key& key) const;
 
     /// Rehashes the table when load factor exceeds maxLoadFactor_.
     void rehash();
 };
 
 template<typename Key, typename Value>
 HashMap<Key, Value>::HashMap(std::size_t buckets)
     : buckets_(buckets), size_(0) {
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
     ++size_;
     if (static_cast<float>(size_) / buckets_ > maxLoadFactor_)
         rehash();
 }
 
 template<typename Key, typename Value>
 bool HashMap<Key, Value>::get(const Key& key, Value& value) const {
     std::size_t index = hash(key);
     for (const auto& pair : table_[index])
         if (pair.first == key) {
             value = pair.second;
             return true;
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
             --size_;
             return;
         }
     }
 }
 
 template<typename Key, typename Value>
 void HashMap<Key, Value>::rehash() {
     buckets_ *= 2;
     std::vector<std::list<std::pair<Key, Value>>> newTable(buckets_);
     for (const auto& cell : table_) {
         for (const auto& pair : cell) {
             std::size_t index = std::hash<Key>{}(pair.first) % buckets_;
             newTable[index].push_back(pair);
         }
     }
     table_.swap(newTable);
 }
 
 } // namespace dsa
 
 #endif // DSA_HASHMAP_HPP
 