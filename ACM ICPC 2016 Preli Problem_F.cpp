
#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pf printf
#define ll long

struct db
{
    ll l,h,v;
};


bool cmp(db a, db b)
{
    if(a.h > b.h) return true;
    else if(a.h == b.h)
    {
        return a.l > b.l;
    }

    return false;
}

int main()
{

    ll t,n,q,low,high,val,test=1,maxx;
    ll arr[120];
    db exe[20020];
    sc("%ld",&t);
    while(t--)
    {
        sc("%ld%ld",&n,&q);
        memset(arr,0,sizeof(arr));
        memset(exe,0,sizeof(exe));
        for(ll i=0;i<q;i++)
        {
            sc("%ld%ld%1ld",&exe[i].l,&exe[i].h,&exe[i].v);
        }

        sort(exe, exe+q, cmp);

        //for(ll i=0;i<q;i++)
            //cerr<<exe[i].l<<" "<<exe[i].h<<" "<<exe[i].v<<endl;
        maxx=0;
        for(ll i=0;i<q;i++)
        {
            low=exe[i].l;
            high=exe[i].h;
            low-=1;
            high-=1;
            val=exe[i].v;
            if(val>maxx)
                maxx=val;
            for(ll j=high;j>=low;j--)
            {
                if(arr[j]==0 || arr[j]<=val)
                {
                    arr[j]=val;
                }
            }
        }

        for(ll i=0;i<n;i++)
            if(arr[i]==0)
                arr[i]=maxx;
        //cout<<"Case "<<test++<<": ";
        pf("Case %ld: ", test++);
        for(ll i=0;i<n-1;i++)
            //cout<<arr[i]<<" ";
            pf("%ld ", arr[i]);
        //cout<<arr[n-1]<<endl;
        pf("%ld\n", arr[n-1]);
    }
    return 0;
}
