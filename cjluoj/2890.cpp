#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        char s;
        long long r;
        while(scanf("%lld%c",&r,&s)!=EOF)
        {
                long long ans=0;
                long long m;
                if((r-1)%4==0)
                {
                        ans=(r-1)/2;
                        m=r-1;
                }
                else if((r-2)%4==0)
                {
                        ans=(r-2)/2+1;
                        m=r-1;
                }
                else if((r-3)%4==0)
                {
                        ans=(r-3)/2;
                        m=r-3;
                }
                else if((r-4)%4==0)
                {
                        ans=(r-4)/2+1;
                        m=r-3;
                }
                ans*=6;
                if(s<='c') ans+=s-'a'+4;
                else ans+='f'-s+1;
                printf("%lld\n",ans+m);
        }
        return 0;
}
