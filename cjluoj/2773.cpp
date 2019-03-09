#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        int N;
        float s,p;
        float sums,sump;
        while(cin>>N)
        {
                sums=0;
                sump=0;
                while(N--)
                {
                        cin>>s>>p;
                        if(p==-1) continue;
                        else
                        {
                                sums+=s;
                                if(p>50)
                                        sump+=s*((p-50)/10);
                        }

                }
                printf("%.2f\n",sump/sums);
        }
        return 0;
}
