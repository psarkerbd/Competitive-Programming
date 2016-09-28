// Under construction

#include<bits/stdc++.h>

using namespace std;

#define high 1000005
#define sf scanf
#define pf printf
#define mxhigh 1000000000005

typedef long long LL;
typedef set<LL>sll;
typedef vector<LL>vll;

int prime[(high >> 6) + 1] , prm[(high>>1) + 9], plen=0 , vlen=0;

vll v;

#define setbit(n) (prime[n >> 6] |= (1 << ((n >> 1) & 31)))
#define checkbit(n) (prime[n >> 6] & (1 << ((n >> 1) & 31)))

void sieve()
{
    int i,j;

    for(i=3; i*i<high; i+=2)
    {
        if(!checkbit(i))
        {
            for(j=i*i; j<high; j+=(2 * i))
            {
                setbit(j);
            }
        }
    }

    prm[plen++] = 2;

    for(i=3; i<high; i+=2)
    {
        if(!checkbit(i))
        {
            prm[plen++] = i;
        }
    }

    //for(i=0; i<100; i++) cout << prm[i] << " ";  //cerr << prm[i] << " ";
}

void init()
{
    int i=0 , j;

    LL pnum=0 , p=1;

    sll st;
    sll::iterator it;

    for(i=0; i<plen; i++)
    {
        pnum = prm[i];

        for(j=2; j<=40; j++)
        {
           //pnum = power(prm[i] , j);

           p=1;

           for(int k=1; k<=j; k++)
           {
               p*=pnum;

               if(p > mxhigh) break;
           }

           if(p < mxhigh)
           {
               st.insert(p);
           }
        }
    }

    //cerr << st.size();

    for(it=st.begin() ; it!=st.end() ; ++it)
    {
        v.push_back(*it);
    }

    //for(i=0; i<100; i++) cout << v[i] << " ";
    //cout << v.size();
    //cout << v[v.size()-1];
    vlen = v.size();
}

int khojlwr(int lo, int hi, LL itm)
{
    int mid;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        if(v[mid] == itm) hi = mid - 1;
        else if(v[mid] > itm) hi = mid - 1;
        else if(v[mid] < itm) lo = mid + 1;
    }

    return lo;
}

int khojupr(int lo, int hi, LL itm)
{
    int mid ;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        if(v[mid] == itm) lo = mid + 1;
        else if(v[mid] > itm) hi = mid - 1;
        else if(v[mid] < itm) lo = mid + 1;
    }

    return lo;
}

int khoj(int lo, int hi, LL itm)
{
    int mid;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        if(v[mid] == itm) return mid;
        else if(v[mid] > itm) hi = mid - 1;
        else if(v[mid] < itm) lo = mid + 1;
    }

    return lo;
}

int main()
{
    sieve();
    init();
    int t, tc=0 , lwr=0 , upr=0;
    LL L , R;

    sf("%d" , &t);

    while(t--)
    {
        sf("%lld %lld" , &L , &R);

        if(L > 3)
        {
            upr = khoj(0 , vlen-1, L);
        }

        else
        {
            upr = 0;
        }

        if(upr > 0)
        {
            if(v[upr] != L)
            {
                upr--;
            }

            if(v[upr] < L) upr++;
        }

        //cout << upr << " " << v[upr] << "\n";

        lwr = khoj(0 , vlen-1, R);

        if(v[lwr] != R)
        {
            lwr--;
        }

        //cout << lwr << " " << v[lwr] << "\n";

        pf("Case %d: %lld\n" , ++tc , lwr - upr + 1);
    }

    return 0;
}
