/*
Lionel Messi is such a player that you may catch him, you may touch him, you may feel him
and definitely you may Love him.
Lionel Messi is Messi. A little Magician in this World.
*/

#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0)
#define bfast cin.tie(0)
#define outs(x) cout << x << " "
#define outn(x) cout << x << "\n"
#define sf scanf
#define pf printf
#define nl puts("")
#define psb push_back
#define mset(c,v) memset(c , v , sizeof c)
#define loop0(n) for(int i=0; i<n; i++)
#define loop1(n) for(int i=1; i<=n; i++)
#define mpair(x , y) make_pair(x , y)
#define all(x) x.begin(), x.end()
#define pi acos(-1.0)
#define psb push_back

typedef unsigned long long ull;
typedef long long LL;
typedef vector<int>vii;
typedef vector<LL>vll;
typedef vector<string>vs;
typedef map<int, int>mpii;
typedef map<string, int>mpsi;
typedef map<char, int>mpci;
typedef map<LL, LL>mpll;

const LL mod = 1000000007;
const LL high = 100005;

LL A[high], B[high], C[high], sumA[high], sumC[high];
vll fromA, fromC;

int main()
{
    int lenA, lenB, lenC, test , i, pos , n , tmplen=0;
    LL cal=0 , ans=0;
    sf("%d", &test);

    while(test--)
    {
        fromA.clear();
        fromC.clear();
        mset(A, 0);
        mset(B, 0);
        mset(C, 0);
        mset(sumA, 0);
        mset(sumC, 0);
        cal = 0;
        ans = 0;

        sf("%d %d %d", &lenA, &lenB, &lenC);

        for(i=0; i<lenA; i++) sf("%lld", &A[i]);
        for(i=0; i<lenB; i++) sf("%lld", &B[i]);
        for(i=0; i<lenC; i++) sf("%lld", &C[i]);

        sort(A, A+lenA);
        sort(B, B+lenB);
        sort(C, C+lenC);

        //for(i=0; i<lenA; i++) cout << A[i] << "; "; cout << "\n";
        //for(i=0; i<lenB; i++) cout << B[i] << "; "; cout << "\n";
        //for(i=0; i<lenC; i++) cout << C[i] << "; "; cout << "\n";

        sumA[0] = A[0] % mod;

        for(i=1; i<lenA; i++) sumA[i] = ((sumA[i-1] % mod) + (A[i] % mod)) % mod;

        sumC[0] = C[0] % mod;

        for(i=1; i<lenC; i++) sumC[i] = ((sumC[i-1] % mod) + (C[i] % mod)) % mod;

        //for(i=0; i<lenA; i++) cout << sumA[i] << "; "; cout << "\n";
        //for(i=0; i<lenB; i++) cout << B[i] << "; "; cout << "\n";
        //for(i=0; i<lenC; i++) cout << sumC[i] << "; "; cout << "\n";

        for(i=0; i<lenB; i++)
        {
            pos = upper_bound(A, A+lenA, B[i]) - A;

            n = pos;

            if(pos>0)
            {
                pos--;

                cal = ((sumA[pos] % mod) + (((n%mod) * (B[i])) % mod)) % mod;

                fromA.push_back(cal);
            }

            else fromA.push_back(0);
        }

        for(i=0; i<lenB; i++)
        {
            pos = upper_bound(C, C+lenC, B[i])-C;

            n = pos;

            if(pos > 0)
            {
                pos--;

                cal = (sumC[pos]%mod + (((n%mod) * (B[i] % mod)) % mod)) % mod;

                fromC.push_back(cal);
            }

            else fromC.push_back(0);
        }

        tmplen = fromA.size();

        for(i=0; i<tmplen; i++)
        {
            ans = ((ans % mod) + ((fromA[i] % mod) * (fromC[i] % mod) % mod)) % mod;
        }

        pf("%lld\n", ans);
    }

    return 0;
}

