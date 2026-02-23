#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product{
    private:
        int categoryId;
        std::string name;
        double price;
        int soldCount;
        int id;
    public:
        Product(int id, int categoryId,const std::string& name , double price)
            :id(id), categoryId(categoryId) , name(name), price(price){}
        int getId()const{
            return categoryId;
        }
        std::string getName() const{
            return name;
        }
        double getPrice() const{
            return price;
        }
        int getSoldCount() const{
            return soldCount;
        }
        int getId() const{
            return id;
        }
        int getCategory() const{
            return categoryId;
        }
        void increaseSoldCount(){
            soldCount++;
        }
};

#endif