#include "City.h"
#include <vector>

class Graph{
private:
    std::vector <City*> cities;
    std::vector<std::vector<std::pair<int, int>>>neighbor;
public:
    ~Graph();
    City* neaest_ware(const City& city);
    std::vector<City*> road(const City& first,const City& second );
    std::vector<City*> findShortPath (const City& first,const City& second );
};