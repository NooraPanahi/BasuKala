#include "City.h"
#include <vector>

class Graph{
private:
    std::vector <City> cities;
    std::vector<std::vector<std::pair<int, int>>>neighbor;
    int nextid = 0;
public:
    std::vector <City> getCitiesList() const;
    std::string getCityNameById(const int& id);
    void addCity(const std::string& name, bool ware);
    void addedge(const int& weight, const int& target, const int& source);
    std::vector<int> dijkstra(int srcId);
    std::pair<int,int> nearestWarehouse(int srcId);
    void dfsPath(int current, int target, const std::vector<int>& dist, std::vector<int>& currentPath, std::vector<int>& bestPath);
    std::vector<int> bestPath(int src, int target);
    std::tuple<int,int,std::vector<int>>getDeliveryRoute(const int& destinationId);
};