#include<stdio.h>
#include<string.h>
int main()
{
        char  num[100000];
        int tot;
        int l;
        int flag;
        int i;
        float ans;
        memset(num,'\0',sizeof(num));
        while(scanf("%s%*c",&num)!=EOF)
        {
                flag=0;
                tot=0;
                l=0;
                i=0;
                if(num[0]=='-')
                {
                        flag=1;
                        i=1;
                }
                for(;num[i]!='\0';i++)
                {
                        if(num[i]=='2')
                                tot++;
                        l++;
                }
                if(flag)
                {
                        if((num[i-1]-'0')%2==0) ans=(float)tot/l*1.5*2*100;
                        else ans=(float)tot/l*1.5*100;
                }
                else
                {
                        if((num[i-1]-'0')%2==0) ans=(float)tot/l*2*100;
                        else ans=(float)tot/l*100;
                }
                printf("%.2f%%\n",ans);
                memset(num,'\0',sizeof(num));
        }
        return 0;
}
