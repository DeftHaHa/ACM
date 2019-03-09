#include<stdio.h>
int max(int a,int b)
{
        if(a>b) return a;
        else return b;
}
int main()
{
        int T;
        int a,b;
        int ans;
        scanf("%d",&T);
        while(T--)
        {
                ans=0;
                scanf("%d%d",&a,&b);
                ans=max(a,b)*5;
                if(ans<=1000)
                        printf("1000\n");
                else if(ans>=60000)
                        printf("60000\n");
                else
                        printf("%d\n",ans);
        }
        return 0;
}
