
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

const int mod = 1000007;
const int high = 1000001;
const int qrt = 1001;

LL ar[high];

int prime[(high >> 6) + 1];

#define setbit(n) (prime[n>>6]|=(1<<((n>>1)&31)))
#define checkbit(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define qrt 10000

vii prm;
int plen = 0;

void sieve()
{
    int i,j;

    for(i=3;i<=qrt;i+=2)
    {
        if(!checkbit(i))
        {
            for(j=i*i;j<=high;j+=i+i)
            {
                setbit(j);
            }
        }
    }

    prm.push_back(2);

    for(i=3;i<=high;i+=2)
    {
        if(!checkbit(i))
        {
            prm.push_back(i);
        }
    }

    plen=prm.size();

    //for(i=0; i<100; i++) cout << prm[i] << "; ";

    //lp1(i,plen)cp(prm[i]);
}

bool isPrime(int n)
{
    if(n == 2) return true;

    if(!(n&1) or n<2)
    {
        return false;
    }

    else
    {
        return (!checkbit(n));
    }

    return true;
}


void precal()
{
    int i=0, num=0 , t=1;
    LL mul = 1;

    mset(ar , 0);

    for(i=0; i<plen; i++)
    {
        num = prm[i];
        //cout << "num = " << num << "\n";
        t=1;
        mul = num * t;

        ar[mul] = t;
        //cout << ar[mul] << " - " << t << "\n";

        while(mul < high)
        {
            t++;
            mul = powl(num , t);

            if(mul < high)
            {
                ar[mul] = t;
                //cout << "mul = " << mul << "-" << ar[mul] << "; ";
                //cout << mul << "-" << ar[mul] << "-" << t << "\n";
            }
        }

        //cout << "\n";
    }
}

int br[high];

int main()
{
    sieve();
    precal();
    int N , Q , i;
    sf("%d", &N);
    for(i=1; i<=N; i++)
    {
        sf("%d", &br[i]);
    }

    int L, R, X, Y , j;

    sf("%d", &Q);

    while(Q--)
    {
        sf("%d %d %d %d", &L , &R, &X , &Y);

        LL res = 0 , ans=0, expo;

        //L--;
        //R--;

        for(i=X; i<=Y; i++)
        {
            res = 0;

            if(isPrime(i))
            {
                //cout << i << "-> ";
                res = 0;

                for(j=L; j<=R; j++)
                {
                    int num = br[j];
                    expo = 0;

                    while(num % i == 0)
                    {
                        expo +=1;
                        num/=i;
                    }

                    ans += expo;
                }
            }
        }

        pf("%lld\n", ans);
    }

    return 0;
}
