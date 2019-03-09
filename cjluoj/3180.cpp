#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        int n;
        while(~scanf("%d",&n))
        {
                if(n==0) break;
                int a,b,c,d;
                a=b=c=d=1;
                if(n<=4) {printf("%d\n",n);continue;}
                else n-=4;
                for(int i=0;i<n;i++)
                {
                        d=(c+d)%10000;
                        c=b;
                        b=a;
                        a=d;
                }
                printf("%d\n",(a+b+c+d)%10000);
        }
        return 0;
}
