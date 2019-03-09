#include<cstdio>
#include<cstring>
int main()
{
        char a[10005];
        char b[10005];
        int i;
        int n;
        int l;
        int t;
        char ch;
        scanf("%d",&n);
        while(n--)
        {
                memset(a,0,sizeof(a));
                memset(b,0,sizeof(a));
                scanf("%s",a);
                strcpy(b,a);
                l=strlen(a);
                t=1;
                for(i=0;i<l;i++)
                {
                        if(a[i]=='l')
                        {
                                if(a[i+1]=='i')
                                {
                                        if(a[i+2]=='m')
                                        {
                                                if(a[i+3]=='m')
                                                {
                                                        strcpy(a+i,"limingming");
                                                        strcpy(a+i+10,b+i+4*t-10*(t-1));
                                                        l+=6;
                                                        t++;
                                                }
                                        }
                                }
                        }
                }
                printf("%s\n",a);
        }

        return 0;
}
