#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int len = 0;
int digitsum = 0;
string s;

bool checklastDigit()
{
    int quotien = digitsum / 3;

    LL x = 3 * (quotien + 1);

    //cout << "x = " << x << "\n";

    //quotien += 1;

    int d = abs(digitsum - x);

    int y = s[len - 1] - 48;

    y += d;

    //cout << "y = " << y << "\n";

    if(y > 9) return false;

    s[len - 1] = y + 48;

    //cout << "Last char = " << s[len-1] << "\n";

    digitsum = 0;

    for(int i=0; i<len; i++)
    {
        digitsum += (s[i] - 48);
    }

    //cout << "funLast = " << digitsum << "\n";

    if(digitsum % 3 == 0) return true;

    return false;
}

bool checkfirstDigit()
{
    int quotien = digitsum / 3;

    LL x = 3 * (quotien + 1);

    //cout << "x = " << x << "\n";

    //quotien += 1;

    int d = abs(digitsum - x);

    int y = s[0] - 48;

    y += d;

    if(y > 9) return false;

    //cout << "firstY = " << y << "\n";

    s[0] = y + 48;

    digitsum = 0;

    for(int i=0; i<len; i++)
    {
        digitsum += (s[i] - 48);
    }

    //cout << "funFirst = " << digitsum << "\n";

    if(digitsum % 3 == 0) return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int test, Tc = 0;
    cin >> test;
    while(test--)
    {
        cin >> s;

        len = s.length();

        digitsum = 0;

        for(int i=0; i<len; i++)
        {
            digitsum += (s[i] - 48);
        }

        //cout << digitsum << "\n";

        int isdivide = digitsum % 3;

        //if(isdivide) cout << "no " << " " << s << " - " << digitsum << "\n";
        //else cout << "yes " << s << " - " << digitsum << "\n";

        cout << "Case " << ++Tc << ": ";

        if(isdivide)
        {
            //cout << s << " - " << digitsum << "\n";

            if(checklastDigit())
            {
                //cout << s << " - " << digitsum << "\n";
                cout << s << "\n";
            }

            else if(checkfirstDigit())
            {
                //cout << s << " - " << digitsum << "\n";
                cout << s << "\n";
            }

            else
            {
                cout << -1 << "\n";
            }
        }

        else
        {
            //cout << s << " - " << digitsum << "\n";
            cout << s << "\n";
        }
    }

    return 0;
}
