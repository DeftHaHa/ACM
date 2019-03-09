#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;
bool a[10000000];
int main()
{
        clock_t start,finish;
    start=clock();
        int N=10000000;
        int n;
        int t=1;
        int c=1;
        int i;
        int p[500005];
        memset(a,true,sizeof(a));
        for(int i=2; i<=sqrt(N); i++)
        {
                if(a[i]==true)
                {
                        for(int j=2; j*i<=N; j++)
                        {
                                a[i*j]=false;
                        }
                }
        }
        for(i=2;i<10000000;i++)
                {
                        if(a[i]==true)
                        {
                                p[t++]=i;
                        }
                        if(t==500001) break;
                }
finish=clock();    cout <<double( finish-start )/CLOCKS_PER_SEC << " (s) "<< endl;
        while(1)
        {
                scanf("%d",&n);
                if(n==0) return 0;
                printf("Case %d: %d\n",c,p[n]);
                c++;
        }
        return 0;
}
