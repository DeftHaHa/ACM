#include<cstring>
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
bool prim[1000000005];
int main()
{
        clock_t start,finish;
        start=clock();

        memset(prim,true,sizeof(prim));
        for(int i=2;i<=31622;i++)
        {
                if(prim[i])
                        for(int j=i*i;j<=1000000000;j+=i)
                        {
                                prim[j]=false;
                        }
        }


        finish=clock();
        cout <<double( finish-start )/CLOCKS_PER_SEC << " (s) "<< endl;

        int T;
        scanf("%d",&T);
        int m,n;
        while(scanf("%d%d",&m,&n)!=EOF)
        {
                for(int i=m;i<=n;i++)
                {
                        if(prim[i]) printf("%d\n",i);
                }
                printf("\n");
        }
        return 0;
}
