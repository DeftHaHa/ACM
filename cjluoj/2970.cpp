#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
        int N;
        int a[25];
        while(scanf("%d",&N)!=EOF)
        {
                if(N==0) break;
                for(int i=0;i<N;i++)
                        scanf("%d",&a[i]);
                int ans=0,sum=0;
                for(int i=0;i<N;i++)
                {
                        sum+=a[i];
                        ans+=abs(sum);
                }
                printf("%d\n",ans);
        }
        return 0;
}
