#include<stdio.h>
#include<string.h>
int main()
{
        char N[1005]={'\0'};
        int ans[10];
        int i;
        while(scanf("%s",N)!=EOF)
        {
                memset(ans,0,sizeof(ans));
                for(i=0;N[i]!='\0';i++)
                        ans[N[i]-'0']++;
                for(i=0;i<=9;i++)
                        if(ans[i]!=0) printf("%d:%d\n",i,ans[i]);
                memset(N,0,sizeof(N));
                printf("\n");
        }
        return 0;
}
