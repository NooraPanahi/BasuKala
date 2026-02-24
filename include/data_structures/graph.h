#include "City.h"
#include <vector>

class Graph{
private:
    std::vector <City*> cities;
    std::vector<std::vector<std::pair<int, int>>>neighbor;
public:
    ~Graph();
    void insert (const std::string& name, const bool& ware );
    std::vector<int> Graph::dijkstra(int srcId);

    std::pair<int,int> nearestWarehouse(int srcId);
    std::vector<City*> path(int dist, int src, int target);
};