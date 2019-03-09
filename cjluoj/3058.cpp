#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        int n;
        int tot;
        int List[50];
        List[1]=1;
        for(int i=2;i<=28;i++)
        {
                List[i]=List[i-1]*2;
        }
        while(scanf("%d",&n)!=EOF)
        {
                if(n==0) break;
                for(int i=28;i>=0;i--)
                {
                        if(List[i]<=n)
                        {
                                printf("%d\n",1+(n-List[i])*2);
                                break;
                        }
                }
        }
        return 0;
}
