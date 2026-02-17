#ifndef CITY_H
#define CITY_H
#include <string>

class City{
    private:
        int id;
        std::string name;
        bool WareHouse;
    public:
        City(int id, const std::string& name, bool house);
        int getId()const;
        std::string getName()const;
        bool hasWareHouse()const;
};

#endif