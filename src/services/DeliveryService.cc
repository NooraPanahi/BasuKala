#include "../../include/services/DeliveryService.h"
#include <stdexcept>
#include "PurchaseService.h"

void DelivaryService::addOrder(const Order &order)
{
    OPQ.push(order);
}

Order DelivaryService::dispatchNext(PurchaseService& p)
{
    if(OPQ.empty())
        throw std::runtime_error("No orders to dispatch");

    Order order = OPQ.pop();

    auto [warehouseId, distance, path] =
        graph.getDeliveryRoute(order.getCityId());

    order.setRoute(warehouseId, distance, path);

    if(warehouseId != -1)
{
    User* u = p.user_getter(order.getUserId());
    if(u)
        u->increaseScore(order.getTotalProducts());
}

    printDeliveryInfo(order);

    return order;
}
void DelivaryService::printDeliveryInfo(const Order& order)
{
    std::cout << "===== Processing Order =====\n";

    std::cout << "Order ID: "
              << order.getOrderId() << '\n';

    std::cout << "Frozen Score (at registration): "
              << order.getFrozenScore() << '\n';

    std::cout << "Destination City ID: "
              << order.getCityId() << '\n';

    std::cout << "Warehouse ID: "
              << order.getWarehouseId() << '\n';

    std::cout << "Distance: "
              << order.getDistance() << '\n';

    std::cout << "Number of Products: "
              << order.getTotalProducts() << '\n';

    std::cout << "Delivery Path: ";

    const std::vector<int>& path = order.getDeliveryPath();
    if(path.empty()){
        std::cout << "No path available";
    } else {
        for(size_t i = 0; i < path.size(); ++i){
            std::cout << path[i];
            if(i != path.size() - 1)
                std::cout << " -> ";
        }
    }

    std::cout << "\n=============================\n";
}

Order DelivaryService::nextOrder() const
{
    if(OPQ.empty())
    throw std::runtime_error("No pending orders");
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

