#pragma once
#include <vector>
#include "../Product.h"
#include <unordered_map>

class ProductMaxHeap {
private:
    std::vector<Product*> heap;
    std::unordered_map<Product*, int>indexMap;
    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    ProductMaxHeap();

    void insert(Product* product);
    Product* top() const;
    Product* extractMax();

    bool empty() const;
    size_t size() const;
    void increaseKey(Product* product);
};