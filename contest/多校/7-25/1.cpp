#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
        int a[100005];
        int i;
        double x=log(2)/log(10);
        for(i=1;i<=100000;i++)
                a[i]=i*x;
        int m,c=1;
        while(scanf("%d",&m)!=EOF)
        {
                printf("Case #%d: %d\n",c++,a[m]);
        }
        return 0;
}
