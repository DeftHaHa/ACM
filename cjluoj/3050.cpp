#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        double f,s,t;
        int dis;
        double ans,sum;
        while(cin>>f>>s>>t)
        {
                dis=0;
                sum=f+s+t;
                ans=sum;
                if(f>=198) dis=2;
                if(s>=50&&dis)  {ans-=10;dis--;}
                if(t>=50&&dis)  {ans-=10;dis--;}
                printf("%.2f %.2f\n",ans,ans/sum);
        }
        return 0;
}
