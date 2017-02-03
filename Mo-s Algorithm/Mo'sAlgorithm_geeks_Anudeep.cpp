#include<bits/stdc++.h>
using namespace std;

const int high=100;

int block;

struct Query
{
    int L , R , i;
};

Query q[high];

int ar[high] , ans[high];

bool cmp(Query a , Query b)
{
    if(a.L/block != b.L/block)
        return a.L/block < b.L/block;

    return a.R < b.R;
}

void queryResults(int n , int qry)
{
    block = (int)sqrt(n);

    sort(q , q+qry, cmp);

    int currR=0, currL=0, currSum=0 , i;

    for(i=0; i<qry; i++)
    {
        int L = q[i].L , R = q[i].R;

        // Removing previous elements

        while(currL < L)
        {
            currSum -= ar[currL];
            currL++;
        }

        // Adding new elements
        while(currL > L)
        {
            currSum += ar[currL-1];
            currL--;
        }

        while(currR <= R)
        {
            currSum += ar[currR];
            currR++;
        }

        while(currR > R+1)
        {
            currSum -= ar[currR-1];
            currR--;
        }

        //cout << "Sum of " << L << " to " << R << " is : " << currSum << "\n";

        int tmp = q[i].i;

        ans[tmp] = currSum;
    }
}

void showResult(int m)
{
    for(int i=0; i<m; i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n , i;
    while(cin >> n)
    {
        for(i=0; i<n; i++)
        {
            cin >> ar[i];
        }

        int qry;
        cin >> qry;

        for(i=0; i<qry; i++)
        {
            cin >> q[i].L >> q[i].R;
            q[i].i = i;
        }

        queryResults(n , qry);
        showResult(qry);
    }

    return 0;
}
