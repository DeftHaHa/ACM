#include<stdio.h>
int main()
{
        int n,m;
        int i;
        char ch;
        int year[100],month[100],day[100];
        int in[100];
        int a,b,c,a1,b1,c1;
        int ans;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                ch=getchar();ch=getchar();
                scanf("%d-%d-%d",&year[i],&month[i],&day[i]);
                in[i]=year[i]*365+month[i]*30+day[i];
        }
        scanf("%d",&m);
        while(m--)
        {
                scanf("%d-%d-%d",&a,&b,&c);
                scanf("%d-%d-%d",&a1,&b1,&c1);
        }
        return 0;
}
