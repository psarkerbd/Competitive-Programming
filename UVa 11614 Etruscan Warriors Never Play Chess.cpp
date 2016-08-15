// Not Submitted

#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false)
#define high 1000000000000000000

typedef long long LL;

//void fun()
//{
//    LL i=1 , sum=0;
//
//    while(sum <= high)
//    {
//        sum+=i;
//        i++;
//        //cout << sum << "; ";
//        if(sum == high)
//        {
//            cout << sum << " " << i;
//            break;
//        }
//    }
//
//    cout << sum << " " << i;
//}


void solution(LL t, LL m)
{
    while(((t*t)+t) <= m)
    {
        t++;
    }

    cout << t-1 << "\n";
}

int main()
{
    fast;
    //fun();
    LL n , test;
    cin >> test;
    while(test--)
    {
//        for(LL i=1; ; i++)
//        {
//            if(((i*i) + i ) / 2 > n)
//            {
//                 cout << "accepted: " << i-1 << "\n" ;
//                 break;
//            }
//        }

        cin >> n;

        if(n == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        LL mul = n << 1; //cout << mul << "\n";
        LL qrt = sqrt(double(mul)) - 1; //cout << "qrt = " << qrt << "\n";

        if( (qrt * qrt) + qrt == mul ) cout << qrt << "\n";
        else if( (qrt * qrt) + qrt > mul ) cout << qrt-1 << "\n" ;
        else if( (qrt * qrt) + qrt < mul )
        {
            LL tmp = qrt+1;
            solution(tmp, mul);
        }
    }

    return 0;
}
