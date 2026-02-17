#ifndef ORDER_H
#define ORDER_H
#include <vector>

class Order{
    private:
        int orderId;
        int userId;
        std::vector<int> productIds;
        double totalPrice;
        int frozenScore;
        int cityId;
        long long timeStamp;
    public:
        Order(int id, int user, const std::vector<int>& products, double totalprice, int score, int city, long long time);
        int getOrderId()const;
        int getUserId()const;
        int getFrozenScore()const;
        long long getTimeStamp()const;
        double getTotalPrice()const;
};

#endif