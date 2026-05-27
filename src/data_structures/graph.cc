#include "../../include/data_structures/graph.h"
#include <unordered_set>
#include <queue>
#include <limits>
// #include <functional>

void Graph::addCity(const std::string &name, bool ware)
{
    cities.emplace_back(nextid, name, ware);
    neighbor.push_back({});
    nextid++;

}
std::vector<City> Graph::getCitiesList() const
{
    return cities   ;
}
std::string Graph::getCityNameById(const int &id)
{
    return cities[id].getName();
}
void Graph::addedge(const int& weight, const int& target, const int& source)
{
    neighbor[source].push_back({target, weight});
    neighbor[target].push_back({source, weight});
}

std::vector<int> Graph::dijkstra(int srcId)
{
    int n = neighbor.size();
    const int INF = 1e9;

    std::vector<int> dist(n, INF);
    dist[srcId] = 0;

    std::priority_queue<
        std::pair<int,int>,
        std::vector<std::pair<int,int>>,
        std::greater<std::pair<int,int>>
    > pq;

    pq.push({0, srcId});

    while (!pq.empty()) {

        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d != dist[u]) continue;

        for (auto edge : neighbor[u]) {

            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
std::pair<int,int> Graph::nearestWarehouse(int srcId)
{
    std::vector<int> dist = dijkstra(srcId);

    int bestId = -1;
    int bestDist = std::numeric_limits<int>::max();

    for (auto c : cities) {
        if (!c.hasWareHouse()) continue;

        int id = c.getId();
        if (id < 0 || id >= (int)dist.size()) continue;   

        if (dist[id] < bestDist) {
            bestDist = dist[id];
            bestId = id;
        }
    }

    if (bestId == -1) return {-1, -1};  
    return {bestId, bestDist};
}

void Graph::dfsPath(int current,
                    int target,
                    const std::vector<int>& dist,
                    std::vector<int>& currentPath,
                    std::vector<int>& bestPath)
{
    currentPath.push_back(current);

    if (current == target)
    {
        if (bestPath.empty() || currentPath.size() < bestPath.size())
        {
            bestPath = currentPath;
        }

        currentPath.pop_back();
        return;
    }

    for (auto edge : neighbor[current])
    {
        int next = edge.first;
        int weight = edge.second;

        if (dist[next] == dist[current] + weight)
        {
            dfsPath(next, target, dist, currentPath, bestPath);
        }
    }

    currentPath.pop_back();
}
std::vector<int> Graph::bestPath(int src, int target)
{
    std::vector<int> dist = dijkstra(src);

    if (target < 0 || target >= (int)dist.size())
        return {};

    if (dist[target] == 1e9)   
        return {};

    std::vector<int> currentPath;
    std::vector<int> bestPath;

    dfsPath(src, target, dist, currentPath, bestPath);

    return bestPath;
}

std::tuple<int,int,std::vector<int>> 
Graph::getDeliveryRoute(const int& destinationId)
{
    if (destinationId < 0 || destinationId >= (int)cities.size())
        return {-1, -1, {}};

    auto [warehouseId, distance] = nearestWarehouse(destinationId);

    if (warehouseId == -1)
        return {-1, -1, {}};

    std::vector<int> path = bestPath(warehouseId, destinationId);

    return {warehouseId, distance, path};
}
