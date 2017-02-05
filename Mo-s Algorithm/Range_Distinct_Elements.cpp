#include<bits/stdc++.h>

using namespace std;

typedef map<int, int>mpii;

const int high = 100;

int ar[high] , ans[high] , block=0;

 mpii mp;

struct Query
{
    int L , R , i;
}q[high];

bool cmp(Query x , Query y)
{
    if(x.L/block != y.L/block) return x.L/block < y.L/block;

    return x.R < y.R;
}

void results(int n , int m)
{
    block = (int)sqrt(n);

    sort(q, q+m , cmp);

    mp.clear();

    int currL=0 , currR=0, tmp=0 , answer=0;

    for(int i=0; i<m; i++)
    {
        int L = q[i].L , R = q[i].R;

        mp.clear();
        //answer = 0;

        while(currL < L)
        {
            mp[ar[currL-1]]++;

            if(mp[ar[currL-1]] == 1) answer++;

            currL++;
        }

        while(currL > L)
        {
            mp[ar[currL]]++;

            if(mp[ar[currL]] == 1) answer++;

            currL--;
        }

        while(currR <= R)
        {
            mp[ar[currR]]++;

            if(mp[ar[currR]] == 1) answer++;

            currR++;
        }

        while(currR > R+1)
        {
            mp[ar[currR-1]]++;

            if(mp[ar[currR-1]] == 1) answer++;

            currR--;
        }

        tmp = q[i].i;

        ans[tmp] = answer;
    }
}

void solution(int m)
{
    for(int i=0; i<m; i++) cout << ans[i] << "\n";
}

int main()
{
    int n , i;

    while(cin >> n)
    {
        for(i=0; i<n; i++) cin >> ar[i];

        int qry;
        cin >> qry;

        for(i=0; i<qry; i++)
        {
            cin >> q[i].L >> q[i].R;
            //q[i].L--;
            //q[i].R;
            q[i].i = i;
        }

        results(n , qry);
        solution(qry);
    }

    return 0;
}
