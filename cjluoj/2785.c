#include<stdio.h>
int main()
{
        int a,b,c;
        int t;
        scanf("%d%d%d",&a,&b,&c);
        if(a>b)
        {
                t=a;
                a=b;
                b=t;
        }
        if(c<a) printf("%d->%d->%d",c,a,b);
        else if(c>b) printf("%d->%d->%d",a,b,c);
        else printf("%d->%d->%d",a,c,b);
        return 0;
}
