#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int Q , len=0 , i;
    string s;

    cin >> Q;

    while(Q--)
    {
        cin >> s;

        len = s.length();

        int one = 0, zero = 0, pattern=0;

        for(i=0; i<len; i++)
        {
            if(s[i] == '1')
            {
                if(zero > 0 && one == 0)
                {
                    zero = 0;
                    one = 1;
                    continue;
                }

                else one += 1;

                if(one == 2 && zero > 0)
                {
                    pattern += 1;
                    one = 1;
                    zero = 0;
                }

                else
                {
                    one = 1;
                }
            }

            else if(s[i] == '0')
            {
                zero += 1;
            }

            else
            {
                zero = 0;
                one = 0;
            }
        }

        cout << pattern << "\n";
    }

    return 0;
}

