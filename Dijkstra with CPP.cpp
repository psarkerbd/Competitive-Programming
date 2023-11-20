#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int high = 1000;
const int inf = INT_MAX;
vector<int>adjacent[high], cost[high];
struct node
{
    int u, cost;
    node(int _u, int _cost)
    {
        u = _u;
        cost = _cost;
    }
    bool operator < (const node &p) const 
    {
        return cost > p.cost;
    }
};

void Dijkstra(int nodes, int start)
{
    int distance[nodes+1], u, v;
    for(int i=1; i<=nodes; i++)
    {
        distance[i] = inf;
    }
    priority_queue<node>Q;
    Q.push(node(start, 0));
    distance[start] = 0;
    while(!Q.empty())
    {
        u = Q.top().u;
        Q.pop();
        for(int i=0; i<adjacent[u].size(); i++)
        {
            v = adjacent[u][i];
            if(distance[u] + cost[u][i] < distance[v])
            {
                distance[v] = distance[u] + cost[u][i];
                Q.push(node(v, distance[v]));
            }
        }
    }
    for(int i=1; i<=nodes; i++)
    {
        cout << "From " << start << " --> " << i << " is " << distance[i] << "\n";
    }
}
int main()
{
    int u, v, w, numNodes, numEdges;
    cin >> numNodes >> numEdges;
    for(int i=0; i<numEdges; i++)
    {
        cin >> u >> v >> w;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int start;
    cout << "Enter start node: ";
    cin >> start;
    Dijkstra(numNodes, start);
    return 0;
}