#ifndef CITY_H
#define CITY_H
#include <string>

class City{
    private:
        int id;
        std::string name;
        bool WareHouse;
    public:
        City(int id, const std::string& name, bool house): id(id), name(name),WareHouse(house){}
        int getId()const{
            return id;
        }
        std::string getName()const{
            return name;
        }
        bool hasWareHouse()const{
            return WareHouse;
        }
};

#endif