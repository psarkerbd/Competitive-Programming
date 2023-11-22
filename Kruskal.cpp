#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int high = 1000;

int parents[high];

struct node
{
    int u, v, w;
    node(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const node &p) const
    {
        return w < p.w;
    }
};

vector<node>edges;

void make_set(int nodes)
{
    for(int i=1; i<=nodes; i++)
    {
        parents[i] = i;
    }
}

int findd(int r)
{
    if(parents[r] == r)
    {
        return r;
    }

    else
    {
        return parents[r] = findd(parents[r]);
    }
}

void Kruskal(int nodes)
{
    sort(edges.begin(), edges.end());
    int sum = 0, cnt = 0;
    for(int i=0; i<edges.size(); i++)
    {
        int u = findd(edges[i].u);
        int v = findd(edges[i].v);
        if(u != v)
        {
            cout << "for " << edges[i].u << " and " << edges[i].v << "\n";
            parents[u] = v;
            sum += edges[i].w;
            cnt += 1;
            if(cnt == nodes - 1)
            {
                break;
            }
        }
    }

    cout << sum << "\n";
    for(int i=1; i<=nodes; i++)
    {
        cout << i << " parent: " << parents[i] << "\n";
    }
}

int main()
{
    int numNodes, numEdges, u, v, w;
    cin >> numNodes >> numEdges;
    make_set(numNodes);
    for(int i=1; i<=numEdges; i++)
    {
        cin >> u >> v >> w;
        edges.push_back(node(u, v, w));
    }
    Kruskal(numNodes);
    return 0;
}