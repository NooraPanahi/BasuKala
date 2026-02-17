#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product{
    private:
        int categoryId;
        std::string name;
        double price;
        int soldCount;
    public:
        Product(int categoryId,const std::string& name , double price);
        int getId()const;
        std::string getName() const;
        double getPrice() const;
        int getSoldCount() const;

        void increaseSoldCount();
};

#endif