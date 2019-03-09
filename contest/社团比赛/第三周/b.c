#include<stdio.h>
int js(int x,char a,int y)
{
        if(a=='+') return x+y;
        else if(a=='-') return x-y;
        else if(a=='*') return x*y;
        else if(a=='/') return x/y;
        else if(a=='%') return x%y;
}
int main()
{
        int T;
        int x,y,z;
        char a,b;
        int ans=0;
        scanf("%d",&T);
        while(T--)
        {

                scanf("%d %c %d %c %d",&x,&a,&y,&b,&z);
                if(a=='+'||(a=='-'&&b!='+'&&b!='-'))
                {
                        ans=js(x,a,js(y,b,z));
                }
                else
                {
                        ans=js(js(x,a,y),b,z);
                }
                printf("%d\n",ans);
        }
        return 0;
}
