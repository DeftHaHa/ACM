#include<cstdio>
#include<cmath>
using namespace std;
long long gcd(long long a,long long b)
{
        long long t;
        long long c;
        if(a<b)
        {
                t=a;
                a=b;
                b=t;
        }
        while(b!=0)
        {
                c=a%b;
                a=b;
                b=c;
        }
        return a;
}
int main()
{
        int N;
        long long a,b;
        long long bb;
        long long ansa,ansb;
        while(scanf("%d",&N)!=EOF)
        {
                scanf("%lld/%lld",&ansa,&ansb);
                N-=1;
                while(N--)
                {
                        scanf("%lld/%lld",&a,&b);
                        bb=b*ansb/gcd(ansb,b);
                        ansa=bb/b*a+bb/ansb*ansa;
                        ansb=bb;
                }
                bb=gcd(ansb,abs(ansa));
                ansb/=bb;
                ansa/=bb;
                if(ansa==0) printf("0\n");
                else if(abs(ansa)>=ansb)
                {
                        if(ansa%ansb==0)
                        {
                                printf("%lld\n",ansa/ansb);
                        }
                        else
                        {
                                printf("%lld ",ansa/ansb);
                                ansa=abs(ansa);
                                printf("%lld/%lld\n",ansa%ansb,ansb);
                        }
                }
                else if(ansa<ansb)
                {
                        printf("%lld/%lld\n",ansa,ansb);
                }
        }
        return 0;
}
