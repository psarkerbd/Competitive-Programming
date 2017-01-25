#include<bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

const int high = 100003;

char ins[high] , robot[high];

int main()
{
    int ins_len=0 , i , robot_len=0;

    while(~sf("%s", &ins))
    {
        sf("%s", &robot);

        ins_len = strlen(ins);
        robot_len = strlen(robot);

        if(robot_len == ins_len)
        {
            for(i=0; i<robot_len; i++)
            {
                if(robot[i] != ins[i])
                {
                    pf("Change the position at %d\n", i+1 );
                }
            }
        }

        else
        {
            pf("your code did not generate the instructions :(\n");
        }
    }

    return 0;
}
