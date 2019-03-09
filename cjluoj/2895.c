#include<stdio.h>
#include<string.h>
int main()
{
        char s[10005];
        int i;
        while(gets(s))
        {
                for(i=0;i<strlen(s);i++)
                {
                        if(s[i]!=','&&s[i]!=' ')
                                s[i]-=1;
                        printf("%c",s[i]);
                }
                printf("\n");
        }

        return 0;
}
