#pragma once
#include "../Order.h"

class OrderPriorityQueue{
private:
    std::vector <Order> heap;
protected:
    bool comparator(const Order& a, const Order& b) const;
    void heapifyUp(int index);
    void heapifyDown(int index);
public:

    void push(const Order& order);

    Order pop();
    Order top() const;
    bool empty() const;
    size_t size() const;




};