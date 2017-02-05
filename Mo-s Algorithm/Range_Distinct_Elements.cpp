#include<bits/stdc++.h>
using namespace std;

const int high = 100;

typedef map<int,int>mpii;

struct Query
{
    int L , R , i;
}q[high];

struct output
{
    int L , R , in;
}ans[high];

int ar[high] , block=0 , answer=0;

mpii mp;

bool cmp(Query x , Query y)
{
    if(x.L/block != y.L/block) return x.L/block < y.L/block;

    return x.R < y.R;
}

void add(int x)
{
    mp[ar[x]]++;

    if(mp[ar[x]] == 1) answer++;
}

void rmoving(int x)
{
    mp[ar[x]]--;

    if(mp[ar[x]] == 0) answer--;
}

void Results(int n , int m)
{
    block = (int)sqrt(n);

    sort(q , q+m , cmp);

    int currL = 0 , currR = 0;

    answer = 0;

    for(int i=0; i<m; i++)
    {
        int L = q[i].L , R = q[i].R;

        //mp.clear();

        // Removing
        while(currL < L)
        {
            rmoving(currL);
            currL++;
        }

        //adding
        while(currL > L)
        {
            add(currL-1);
            currL--;
        }

        while(currR <= R)
        {
            add(currR);
            currR++;
        }

        while(currR > R+1)
        {
            rmoving(currR-1);
            currR--;
        }

        int indx = q[i].i;

        //ans[indx] = answer;

        ans[indx].in = answer;

        //answer = 0;
    }
}

void solution(int m)
{
    cout << "Number of Distinct Elements:\n";

    for(int i=0; i<m; i++)
    {
        cout << "From " << ans[i].L << " to " << ans[i].R << " = " << ans[i].in << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n , i;

    cout << "Number of Elements: ";

    while(cin >> n)
    {
        mp.clear();

        answer = 0;

        for(i=0; i<n; i++)
        {
            cin >> ar[i];
        }

        cout << "Number of Query: ";

        int qry;
        cin >> qry;

        for(i=0; i<qry; i++)
        {
            cin >> q[i].L >> q[i].R;

            //q[i].L--;
            //q[i].R--;

            q[i].i = i;

            ans[i].L = q[i].L;
            ans[i].R = q[i].R;
        }

        Results(n , qry);
        solution(qry);

        cout << "Number of Elements: ";
    }

    return 0;
}
