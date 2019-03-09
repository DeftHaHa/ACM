#include<stdio.h>
int main()
{
        int n;
        int i;
        scanf("%d",&n);
        char s[100];
        getchar();
        while(n--)
        {
                gets(s);
                for(i=0;s[i]!='\0';i++)
                {
                        if(s[i]==34)  printf("\\");
                        printf("%c",s[i]);
                        if(s[i]=='\\')  printf("\\");
                        else if(s[i]==37)  printf("%%");
                }
                printf("\n");
        }

        return 0;
}
