/*  Topological Sorting (Basic) */

#include<bits/stdc++.h>
using namespace std;

#define sf scanf
#define pf printf
#define psb push_back

const int high = 1e3+5;

vector<int>adj[high];
vector<int>sortedList;

int indegree[high], visited[high];
bool sp = false;

void input_graph(int edges)
{
    int u , v;

    for(int i=0; i<edges; i++)
    {
        sf("%d %d", &u , &v);

        indegree[v]++;

        adj[u].psb(v);
    }
}

void Topo_Sort(int nodes)
{
    queue<int>Q;

    int i , u , v;

    for(i=1; i<=nodes; i++)
    {
        if(indegree[i] == 0)
        {
            Q.push(i);
        }
    }

    while(!Q.empty())
    {
        u = Q.front();

        sortedList.push_back(u);

        visited[u] = 1;

        Q.pop();

        int sze = adj[u].size();

        for(i=0; i<sze; i++)
        {
            v = adj[u][i];

            if(indegree[v] > 0)
            {
                indegree[v]--;
            }

            if(indegree[v]==0 && visited[v]==0)
            {
                Q.push(v);
                visited[v] = 1;
            }
        }
    }
}

int main()
{
    int nodes, edges, i , j;

    sf("%d %d", &nodes, &edges);

    input_graph(edges);


    Topo_Sort(nodes);

    int sze = sortedList.size();

    cout << "Sorted Order is: ";

    cout << sortedList[0];

    for(i=1; i<sze; i++)
    {
        cout << " -> " << sortedList[i];
    }

    return 0;
}

/*
6 8
1 3
2 3
3 4
3 5
3 6
4 5
6 4
6 5

*/
