#include "pch.h"
#include "../zaawansowane3/MergeSort.h"
#include <vector>
#include <algorithm>
#include <random>

TEST(MergeSortTest, AlreadySortedAscending) {
    MergeSort<int> sorter;
    std::vector<int> actual = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, ReverseOrder) {
    MergeSort<int> sorter;
    std::vector<int> actual = { 9, 7, 5, 3, 1 };
    std::vector<int> expected = { 1, 3, 5, 7, 9 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, RandomNumbers) {
    MergeSort<int> sorter;
    std::vector<int> actual = { 42, -15, 0, 19, 3, -8, 100, 27 };
    std::vector<int> expected = actual;
    std::sort(expected.begin(), expected.end());

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, OnlyNegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> actual = { -4, -100, -1, -25, -7 };
    std::vector<int> expected = { -100, -25, -7, -4, -1 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, NegativeAndPositiveNumbers) {
    MergeSort<int> sorter;
    std::vector<int> actual = { -10, 25, -3, 0, 14, -1, 8 };
    std::vector<int> expected = { -10, -3, -1, 0, 8, 14, 25 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, EmptyArrayNoException) {
    MergeSort<int> sorter;
    std::vector<int> actual = {};
    std::vector<int> expected = {};

    EXPECT_NO_THROW(sorter.sort(actual));
    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, SingleElementArray) {
    MergeSort<int> sorter;
    std::vector<int> actual = { 42 };
    std::vector<int> expected = { 42 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, DuplicatesOnlyPositive) {
    MergeSort<int> sorter;
    std::vector<int> actual = { 5, 2, 5, 1, 2, 5, 3 };
    std::vector<int> expected = { 1, 2, 2, 3, 5, 5, 5 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, NegativeWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> actual = { -5, -12, -5, -1, -12, -8 };
    std::vector<int> expected = { -12, -12, -8, -5, -5, -1 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, NegativePositiveAndDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> actual = { 4, -7, 0, 4, -7, 12, 0, -2, 12 };
    std::vector<int> expected = { -7, -7, -2, 0, 0, 4, 4, 12, 12 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, TwoElementsAscending) {
    MergeSort<int> sorter;
    std::vector<int> actual = { 10, 20 };
    std::vector<int> expected = { 10, 20 };

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, LargeArrayOver100Elements) {
    MergeSort<int> sorter;
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 10000);

    std::vector<int> actual(150);
    for (int& x : actual) {
        x = dist(rng);
    }

    std::vector<int> expected = actual;
    std::sort(expected.begin(), expected.end());

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}

TEST(MergeSortTest, LargeArrayOver100WithNegativesPositivesAndDuplicates) {
    MergeSort<int> sorter;
    std::mt19937 rng(123);
    std::uniform_int_distribution<int> dist(-25, 25);

    std::vector<int> actual(200);
    for (int& x : actual) {
        x = dist(rng);
    }

    std::vector<int> expected = actual;
    std::sort(expected.begin(), expected.end());

    sorter.sort(actual);

    EXPECT_EQ(actual, expected);
}