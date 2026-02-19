#pragma once
#include "../data_structures/StablePriorityQueue.h"

class DelivaryService{
private:
    OrderPriorityQueue OPQ;
public:
void addOrder(const Order& order);
Order dispatchNext();
Order nextOrder() const;
bool hasOrders() const;
size_t pendingCount() const;
};