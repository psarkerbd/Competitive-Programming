/*
Uva 1585 Score
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,cnt,add;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> s;

        cnt=0; add=0;

        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='O' or s[i]=='o' or s[i]=='0')
            {
                cnt+=1;
                add+=cnt;
            }

            else
            {
                cnt=0;
            }
        }

        cout << add << endl;
    }

    return 0;
}
