/*

    Accepted
    Algorithm: BFS

    The hard tusk of this problem is to make adjacency lists. If you construct
    it once none will be hard for you :D
    Then run BFS.

*/


#include<bits/stdc++.h>
using namespace std;

#define sf scanf
#define pf printf
#define fast ios_base::sync_with_stdio(false)

const int high = 5005;
typedef map<string, int>mpsi;

vector<int>adj[high];
vector<int>authorlist;

int cost[high], visited[high];

mpsi mp;

void CLR()
{
    for(int i=0; i<high; i++)
    {
        adj[i].clear();
        visited[i] = 0;
        cost[i] = 0;
    }

    mp.clear();
}

void AdjacencyList(int n)
{
    int i , j, len=0, num=1;
    string authors;

    mp["Erdos, P."] = 1;

    while(n--)
    {
        authorlist.clear();

        getline(cin, authors);

        len = authors.length();

        int j=0, comma = 0, mid=0;

        string single_author="";

        len = authors.length();

        for(i=0;i<len;i++)
        {
            if(authors[i]==','|| authors[i]==':')
            {
                comma++;

                single_author="";

                if(comma==2)
                {
                    comma=0;
                    mid = i;

                    for(;j<mid;j++)
                    {
                        single_author+=authors[j];
                    }

                    j+=2; // I have jumped by 2 to avoid the spaces between two strings

                    if(mp[single_author]==0)
                    {
                        num++;
                        mp[single_author]=num;
                    }

                    //cout<<single_author<<" "<<mp[single_author]<<"\n";

                    authorlist.push_back(mp[single_author]);
                }
            }
        }

//        for(i=0;i<authorlist.size();i++)
//        {
//            cout<<authorlist[i]<<" ";
//        }
//        cout << "\n";

        len=authorlist.size();

        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                adj[authorlist[i]].push_back(authorlist[j]);
                adj[authorlist[j]].push_back(authorlist[i]);
            }
        }
    }
}

void BFS(int s, int des)
{
    visited[s] = 1;
    cost[s] = 0;

    queue<int>Q;
    Q.push(s);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        if(u==des) return;

        int sze = adj[u].size();

        for(int i=0;i<sze;i++)
        {
            int v=adj[u][i];

            if(!visited[v])
            {
                visited[v] = 1;
                cost[v] = cost[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    fast;
    int test, P, N, tc=0;
    string x;
    cin >> test;

    while(test--)
    {
        CLR();

        cin >> P >> N;

        cin.ignore();

        AdjacencyList(P);

        cout << "Scenario " << ++tc << "\n";

        while(N--)
        {
            for(int i=0;i<high;i++) visited[i]=0, cost[i]=0;

            getline(cin, x);

            int des = mp[x];

            BFS(1, des);

            cout << x << " ";

            if(cost[des]==0)
            {
                cout<<"infinity\n";
            }

            else
            {
                cout<<cost[des]<<"\n";
            }
        }
    }

    return 0;
}

