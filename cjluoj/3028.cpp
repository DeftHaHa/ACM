#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        int M,N;
        int i;
        while(scanf("%d%d",&M,&N)!=EOF)
        {
                if(N>=M)
                {
                        printf("%d",M);
                        for(i=M+1;i<=N;i++) printf(" %d",i);
                }
                else
                {
                        int ans=M%(N+1);
                        if(ans==0) printf("none");
                        else
                        {
                                printf("%d",ans);
                        }
                }
                printf("\n");
        }
        return 0;
}
