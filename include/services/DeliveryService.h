#pragma once
#include "../data_structures/StablePriorityQueue.h"
#include "../data_structures/graph.h"
#include "../PurchaseService.h"
#include <iostream>

class DelivaryService{
private:
    OrderPriorityQueue OPQ;
    Graph& graph;
public:
DelivaryService(Graph& g) : graph(g) {}
void addOrder(const Order& order);
Order dispatchNext(PurchaseService& p);
Order nextOrder() const;
bool hasOrders() const;
size_t pendingCount() const;
void printDeliveryInfo(const Order& order);
};