#include "../../include/services/DeliveryService.h"


void DelivaryService::addOrder(const Order &order)
{
    OPQ.push(order);
}

Order DelivaryService::dispatchNext()
{
    return OPQ.pop();
}

Order DelivaryService::nextOrder() const
{
    return OPQ.top();
}

bool DelivaryService::hasOrders() const
{
    return !OPQ.empty();
}

size_t DelivaryService::pendingCount() const
{
    return OPQ.size();
}

