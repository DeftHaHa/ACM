#include<cstdio>
#include<cstring>
using namespace std;
bool s[500005];
long long g[500005];
int main()
{
        int T;
        long long M;
        char ch;

        long long maxq,maxh;
        long long sum;
        long long sumq,sumh;
        long long i;
        scanf("%d",&T);
        while(T--)
        {
                memset(g,0,sizeof(g));
                scanf("%lld",&M);
                sum=0;
                for(i=0;i<M;i++)
                        scanf("%lld",&g[i]);
                ch=getchar();
                for(i=0;i<M;i++)
                {
                        scanf("%c",&ch);
                        if(ch=='A') s[i]=false;
                        else if(ch=='B')
                        {
                                s[i]=true;
                                sum+=g[i];
                        }
                }
                maxq=sum;
                sumq=sum;
                for(i=0;i<M;i++)
                {
                        if(s[i]) sumq-=g[i];
                        else sumq+=g[i];
                        if(sumq>maxq) maxq=sumq;
                }
                maxh=sum;
                sumh=sum;
                for(i=M-1;i>=0;i--)
                {
                        if(s[i]) sumh-=g[i];
                        else sumh+=g[i];
                        if(sumh>maxh) maxh=sumh;
                }
                if(maxq>maxh) printf("%lld\n",maxq);
                else printf("%lld\n",maxh);
        }
        return 0;
}
