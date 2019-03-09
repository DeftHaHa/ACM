#include<stdio.h>
int main()
{
        int T;
        int i,t;
        int g;
        int flag;
        char a[1000];
        scanf("%d",&T);
        getchar();
        while(T--)
        {
                t=0;
                for(i=0;i<1000;i++)
                {
                        scanf("%c",&a[i]);
                        if(a[i]=='\n') break;
                        t++;
                }
                g=0;
                flag=0;
                for(i=14;i<t;i++)
                {
                        if(a[i]=='?') printf("-_-\n");
                        else if(a[i]=='.') printf("Orz\n");
                        else if(a[i]=='!')
                        {
                                g++;
                                flag=1;
                        }

                }
                if(flag==1)
                {
                        printf("W");
                        for(i=0;i<g;i++)
                        printf("o");
                        printf("w!\n");
                }
        }
        return 0;
}
