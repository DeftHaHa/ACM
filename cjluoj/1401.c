#include<stdio.h>
#include<string.h>
int main()
{
        int T;
        int M;
        char ch;
        int g[500005];
        bool s[500005]={false};
        int i;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d",&M);
                for(i=0;i<M;i++)
                        scanf("%d",&g[i]);
                for(i=0;i<M;i++)
                {
                        scanf("%c",&ch);
                        if(ch=='A') s[i]=false;
                        else s[i]=true;
                }
                for(i=0;i<M;i++)
                {
                        printf("%d",s[i]);
                }

        }
}
