#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>adj[100];
const int white = 0, grey = -1, black = 1;
vector<int>sorted_nodes;
void visit(int color[], int s)
{
    color[s] = grey;
    int u = s;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(color[v] == white)
        {
            visit(color, v);
        }
    }
    color[u] = black;
    sorted_nodes.push_back(u);
}
void Topological_sort(int nodes)
{
    int color[nodes+1];
    for(int i=1; i<=nodes; i++)
    {
        color[i] = white;
    }

    for(int i=1; i<=nodes; i++)
    {
        if(color[i] == white)
        {
            visit(color, i);
        }
    }
    cout << "\nSorted Order:\n";
    reverse(sorted_nodes.begin(), sorted_nodes.end());
    cout << sorted_nodes[0];
    for(int i=1; i<sorted_nodes.size(); i++)
    {
        cout << " -> " << sorted_nodes[i];
    }
}
int main()
{
    int nodes, edges;
    cout << "Enter Nodes and Edges: ";
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cout << "Enter Edge " << i+1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
        cout << "\n";
    }
    Topological_sort(nodes);
    return 0;
}