#include<bits/stdc++.h>
using namespace std;

typedef vector<int>vii;

const int high = 4000;

vii adj[high];

int cost[high] , cnt=0;

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

        //cout << u << "-";

        for(int i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];

            if(!visited[v])
            {
                cost[v] = cost[u] + 1;

                if(cost[v] > val)
                {
                    //visited[v] = false;
                    cnt+=1;
                }

                //else visited[v] = true;

                //cout << v << "(" << cost[v] << "); ";

                visited[v] = true;

                Q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N , i , x , y , start , val , tc=0;
    while(cin >> N)
    {
        if(!N) break;

        CLR(N);
        cnt = 0;
        memset(cost , 0, sizeof cost);
        memset(visited , false , sizeof visited);

        for(i=0; i<N; i++)
        {
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        start = 0;
        val = 0;

        while(cin >> start >> val)
        {
            if(!start && !val) break;

            memset(cost , 0, sizeof cost);
            memset(visited , false , sizeof visited);

            cnt = 0;

            BFS(start , val);

            cout << "Case " << ++tc << ": " << cnt << " nodes not reachable from node " << start << " with TTL = " << val << ".\n";
        }
    }

    return 0;
}
