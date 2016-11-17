// Hackerearth City and Flood
// Accepted

#include<bits/stdc++.h>

using namespace std;

typedef map<int, bool>mpbi;

const int high = 100003;

int par[high], Rank[high];

void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        par[i] = i;
        Rank[i] = 0;
    }
}

int find_parent(int n)
{
    if(par[n] == n)
    {
        return n;
    }

    else
    {
        return par[n] = find_parent(par[n]);
    }
}

void check_parent(int a , int b)
{
    if(Rank[a] > Rank[b])
    {
        par[b] = a;
    }

    else
    {
        par[a] = b;

        if(Rank[a] == Rank[b])
        {
            Rank[b]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n , k , i , j , px, py;
    mpbi mp;

    cin >> n >> k;

    init(n); // make_set or initiaization

    while(k--)
    {
        cin >> i >> j;

        px = find_parent(i); // find function
        py = find_parent(j); // find function

        if(px != py)
        {
            check_parent(px, py); // union function
        }
    }

    //for(i=1; i<=n; i++) cout << par[i] << " ";

    int cnt=0;

    for(i=1; i<=n; i++)
    {
        if(par[i] == i)
        {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
