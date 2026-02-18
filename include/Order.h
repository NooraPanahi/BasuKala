#ifndef ORDER_H
#define ORDER_H

#include <vector>

class Order {
private:
    int orderId;
    int userId;
    std::vector<int> productIds;
    double totalPrice;
    int frozenScore;
    int cityId;
    long long timeStamp;

public:
    Order(int id,
          int user,
          const std::vector<int>& products,
          double totalprice,
          int score,
          int city,
          long long time)
        : orderId(id),
          userId(user),
          productIds(products),
          totalPrice(totalprice),
          frozenScore(score),
          cityId(city),
          timeStamp(time)
    {}

    int getOrderId() const {
        return orderId;
    }

    int getUserId() const {
        return userId;
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
};

#endif
