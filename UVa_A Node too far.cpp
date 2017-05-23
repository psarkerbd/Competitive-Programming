#include<bits/stdc++.h>
using namespace std;

typedef vector<int>vii;

const int high = 100;

vii adj[high];

int cost[high];

bool visited[high];

void CLR(int N)
{
    for(int i=0; i<=N; i++)
    {
        adj[i].clear();
    }
}

void BFS(int s , int val)
{
    visited[s] = true;

    int u, v=0;

    cost[s] = 0;

    queue<int>Q;

    Q.push(s);

    while(!Q.empty())
    {
        u = Q.front();

        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];

            if(!visited[v])
            {
                cost[v] = cost[u] + 1;
                visited[v] = true;
                Q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N , i , x , y;
    while(cin >> N)
    {
        memset(visited , false , sizeof visited);
        memset(cost , 0, sizeof cost);
        CLR(N);

        for(i=0; i<N; i++)
        {
            cin >> x >> y;

            adj[x].push_back(y);
        }

        int start=0 , val=0;

        cin >> start >> val;

        BFS(start , val);
    }

    return 0;
}
