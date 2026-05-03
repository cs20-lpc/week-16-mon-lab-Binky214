#pragma once
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class MinHeap {
private:
    vector<T> data;   // complete binary tree stored in array

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void siftUp(int i);
    void siftDown(int i);

public:
    MinHeap() {}

    void insert(const T& value);
    T removeRoot();
    void removeAt(int index);
    int size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    const vector<T>& getArray() const { return data; }
};

#include "MinHeap.tpp"