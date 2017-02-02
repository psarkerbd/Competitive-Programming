#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("output12.txt", "w" , stdout);
    string s , expected="mir" , numbers="";

    int t, tc=0 , len=0 , i , j=0;

    map<char, int>mp , first, last;

    cin >> t;

    while(t--)
    {
        cin >> s;
        mp.clear();
        first.clear();
        last.clear();

        expected="mir";
        numbers="";
        string predict="" , original_pass="" , tmp="";

        len = s.length();

        for(i=0; i<len; i++)
        {
            if(s[i]=='m' or s[i]=='i' or s[i]=='r')
            {
                if(!mp[s[i]])
                {
                    predict+=s[i];
                    mp[s[i]]=1;
                    first[s[i]] = i+1;
                }

                last[s[i]] = i+1;
            }

            if(s[i]>='0' and s[i]<='9')
            {
                numbers+=s[i];
            }
        }

        //cout << predict << "\n";

        if((predict == expected) and (!numbers.empty()))
        {
            //cout << "kichu ekta\n";
            int m_dist = last['m'] - first['m'];
            int i_dist = last['i'] - first['i'];
            int r_dist = last['r'] - first['r'];
            //cout << m_dist << " " << i_dist << " " << r_dist << "\n" ;
            stringstream ss;
            ss << m_dist;
            ss >> tmp;
            original_pass+=tmp;

            tmp="";

            stringstream ss1;
            ss1 << i_dist;
            ss1 >> tmp;
            original_pass+=tmp;

            tmp="";

            stringstream ss2;
            ss2 << r_dist;
            ss2 >> tmp;
            original_pass+=tmp;

            //cout << original_pass << "\n";

            sort(numbers.rbegin(), numbers.rend());

            original_pass+=numbers;

            //cerr << original_pass << "\n";

            if(original_pass[0]=='0')
            {
                i=0;

                while(original_pass[i]=='0')
                {
                    original_pass.erase(original_pass.begin()+i);
                    //i++;
                }

                if(original_pass[0]=='0') original_pass.erase(original_pass.begin()+0);
            }

            if(original_pass.empty()) cout << "regenerate it\n";
            else cout << original_pass << "\n";
        }

        else
        {
            cout << "regenerate it\n";
        }
    }

    return 0;
}
