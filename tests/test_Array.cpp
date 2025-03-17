/**
 * @file test_Array.cpp
 * @brief Tests the DynamicArray class.
 */

#include <gtest/gtest.h>
#include "dsa/Array.hpp"

// Unit Tests
TEST(ArrayTest, PushBack) {
    dsa::DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, PopBack) {
    dsa::DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.pop_back();
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
}

TEST(ArrayTest, Clear) {
    dsa::DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.clear();
    EXPECT_EQ(arr.size(), 0);
    EXPECT_TRUE(arr.empty());
}

// Converting property-based tests to regular unit tests
TEST(ArrayTest, PushBackIncreasesSize) {
    dsa::DynamicArray<int> arr;
    std::vector<int> values = {1, 2, 3, 4, 5};
    for (int value : values) {
        arr.push_back(value);
    }
    EXPECT_EQ(arr.size(), values.size());
}

TEST(ArrayTest, PopBackDecreasesSize) {
    dsa::DynamicArray<int> arr;
    std::vector<int> values = {1, 2, 3, 4, 5};
    for (int value : values) {
        arr.push_back(value);
    }
    size_t original_size = arr.size();
    if (!arr.empty()) {
        arr.pop_back();
        EXPECT_EQ(arr.size(), original_size - 1);
    }
}

TEST(ArrayTest, ClearMakesEmpty) {
    dsa::DynamicArray<int> arr;
    std::vector<int> values = {1, 2, 3, 4, 5};
    for (int value : values) {
        arr.push_back(value);
    }
    arr.clear();
    EXPECT_TRUE(arr.empty());
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, AccessPreservesValues) {
    dsa::DynamicArray<int> arr;
    std::vector<int> values = {1, 2, 3, 4, 5};
    for (int value : values) {
        arr.push_back(value);
    }
    for (size_t i = 0; i < values.size(); ++i) {
        EXPECT_EQ(arr[i], values[i]);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
 