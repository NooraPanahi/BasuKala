#include "graph.h"
#include <unordered_set>
#include <queue>
#include <limits>
// #include <functional> 


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
        if (!c->hasWareHouse()) continue;

        int id = c->getId();
        if (id < 0 || id >= (int)dist.size()) continue;   

        if (dist[id] < bestDist) {
            bestDist = dist[id];
            bestId = id;
        }
    }

    if (bestId == -1) return {-1, -1};  
    return {bestId, bestDist};
}

std::vector <int> bestPath(const int& src, const int&  target, const int&  dist){
    std::pair<std::vector<int>,bool> miniDistance;
    // for(auto neigh : n)


}