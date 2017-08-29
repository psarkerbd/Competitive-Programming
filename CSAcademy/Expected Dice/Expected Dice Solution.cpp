#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0)
#define bfast cin.tie(0)
#define outs(x) cout << x << " "
#define outn(x) cout << x << "\n"
#define sf scanf
#define pf printf
#define pfn(x , k) printf(k , x)
#define nl puts("")
#define psb push_back
#define mset(c,v) memset(c , v , sizeof c)
#define loop0(n) for(int i=0; i<n; i++)
#define loop1(n) for(int i=1; i<=n; i++)
#define mpair(x , y) make_pair(x , y)
#define all(x) x.begin(), x.end()
#define pi acos(-1.0)
#define psb push_back
#define clr clear()

typedef unsigned long long ull;
typedef long long LL;
typedef vector<int>vii;
typedef vector<LL>vll;
typedef vector<string>vs;
typedef map<int, int>mpii;
typedef map<string, int>mpsi;
typedef map<char, int>mpci;
typedef map<LL, LL>mpll;

const int mod = 1000007;
const int high = 101;

vii dice1, dice2 , allsum(high);

int main()
{
    fast;

    int mx = 0;

    int x , i , j=0;

    for(i=0; i<6; i++)
    {
        cin >> x;
        dice1.psb(x);
    }

    for(i=0; i<6; i++)
    {
        cin >> x;
        dice2.psb(x);
    }

    int len1 = dice1.size() , len2 = dice2.size() , ans = 0;

    for(i=0; i<len1; i++)
    {
        for(j=0; j<len2; j++)
        {
            int sum = dice1[i] + dice2[j];

            allsum[sum]+=1;
        }
    }

    for(i=0; i<high; i++)
    {
        if(allsum[i] > mx)
        {
            mx = allsum[i];
            ans = i;
        }
    }

    cout << ans << '\n';

    return 0;
}
