#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
        int n;
        float a,b;
        while(scanf("%d",&n)!=EOF)
        {
                a=sqrt(n*n-1);
                b=sqrt(n*n+2*n);cout<<a<<' '<<b<<' '<<a*b<<'='<<(int)a*(int )b<<endl;
                //printf("%d\n",ans+1);
        }
        return 0;
}
