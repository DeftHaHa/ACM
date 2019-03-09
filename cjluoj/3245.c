#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
        char s[100];
        int n;
        int i;
        while(scanf("%d",&n)!=EOF)
        {
                memset(s,0,sizeof(s));
                itoa(n,s,16);
                for(i=1;i<=8-strlen(s);i++) printf("0");
                printf("%s\n",s);
        }
        return 0;
}
