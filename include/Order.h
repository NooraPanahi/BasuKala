#ifndef ORDER_H
#define ORDER_H

#include <vector>

class Order {
private:
    int orderId;
    std::vector<int> productIds;
    double totalPrice;
    int frozenScore;
    int cityId;
    int distance;
    std::vector<int> deliveryPath; 
       int warehouseId;
    long long timeStamp;

public:
    Order(int id,
          const std::vector<int>& products,
          double totalprice,
          int score,
          int city,
          long long time)
        : orderId(id),
  distance(0),
  warehouseId(-1),
          productIds(products),
          totalPrice(totalprice),
          frozenScore(score),
          cityId(city),
          timeStamp(time)
    {}

    int getOrderId() const {
        return orderId;
    }

    int getFrozenScore() const {
        return frozenScore;
    }

    long long getTimeStamp() const {
        return timeStamp;
    }

    double getTotalPrice() const {
        return totalPrice;
    }
    int getCityId() const{
        return cityId;
    }
    int getTotalProducts() const{
        return productIds.size();
    }

    void setRoute(int warehouseId, int distance, std::vector<int> deliveryPath){
        this->warehouseId = warehouseId;
        this->distance = distance;
        this->deliveryPath = deliveryPath;
    }
    int getWarehouseId() const { return warehouseId; }
int getDistance() const { return distance; }
const std::vector<int>& getDeliveryPath() const { return deliveryPath; }
};

#endif
