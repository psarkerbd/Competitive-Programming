// RMQ by Segment Tree

#include<bits/stdc++.h>
using namespace std;

#define high 100

int ar[high] , tree[high * 4]={-1};

void build(int node , int b , int e)
{
    if(b == e)
    {
        tree[node] = b;
        //return;
    }

    else
    {
        //int left = node * 2;
        //int right = (node * 2) + 1;
        //int mid = (b + e) / 2;

        build(node * 2 , b , (b + e)/2);
        build((node * 2)+1 , ((b+e)/2) + 1 , e);

        if(ar[tree[node * 2]] <= ar[tree[(node * 2)+1]])
        {
            tree[node] = tree[node * 2];
        }

        else
        {
            tree[node] = tree[(node * 2)+1];
        }
    }
}

int query(int node, int b , int e , int i , int j)
{
    if(i > e or j < b)
    {
        return -1;
    }

    if(b >= i and e <= j)
    {
        return tree[node];
    }

    //int left = node * 2;
    //int right = (node * 2) + 1;
    //int mid = (b + e) / 2;

    int p1 = query(node * 2 , b , (b+e)/2, i , j);
    int p2 = query((node * 2)+1 , ((b+e)/2)+1, e , i , j);

    //return min(p1, p2);

    if(p1 == -1)
    {
        //return tree[node] = p2;
        return p2;
    }

    if(p2 == -1)
    {
        //return tree[node] = p1;
        return p1;
    }

    if(ar[p1] <= ar[p2])
    {
        //return tree[node] = p1;
        return p1;
    }

      //return tree[node] = p2;
      return p2;
}

int main()
{
    int n , i , j , q;
    cout << "array indexing from 0\n";

    cout << "Take Size: ";

    while(cin >> n)
    {
        cout << "--Element inserting Start--\n";

        for(i=0; i<n; i++)
        {
            cin >> ar[i];
            cout << ar[i] << " index = " << i << "\n";
        }

        cout << "---Element inserting End--\n";

        build(1 , 0 , n-1);

        cout << "Take number of Query: ";

        cin >> q;

        cout << "\n--- Query Start----(i to j)\n";

        while(q--)
        {
            cin >> i >> j;

            int ans = query(1 , 0 , n-1, i , j);

            //build(1 , 0, n-1);

            cout << "index = " << ans << " value -> " << ar[ans] << "\n";
        }

        cout << "\n---Query End----";

        cout << "Take Size: ";
    }

    return 0;
}
