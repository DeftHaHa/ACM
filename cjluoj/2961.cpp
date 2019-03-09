#include<iostream>
#inlucde<cstring>
using namespace std;
int main()
{
        bool direction;
        int N,tb,te;
        int t[105],from[105],to[105];
        while(cin>>N>>tb>>te)
        {
                if(N+tb+te==0) break;
                int tot=0;
                while(1)
                {
                        cin<<t[tot]>>from[tot]>>to[tot];
                        if(t[tot]+from[tot]+to[tot]=0) break;
                        tot++;
                }
                int time=tb;

        }
        return 0;
}
