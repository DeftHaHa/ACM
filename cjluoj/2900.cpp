#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
        int n,c=1;
        int maxn,minn;
        int sum;
        int t,tot;
        while(cin>>n)
        {
                if(n==0) break;
                tot=n-1;
                cin>>t;
                maxn=minn=sum=t;
                while(tot--)
                {
                        cin>>t;
                        if(t>maxn) maxn=t;
                        if(t<minn) minn=t;
                        sum+=t;
                }
                printf("Case %d:%d %d %.3f\n\n",c++,minn,maxn,(float)sum/(float)n);

        }
        return 0;
}
