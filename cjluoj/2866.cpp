#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        int f;
        int m,h;
        while(scanf("%d",&f)!=EOF)
        {
                scanf("%d:%d",&h,&m);
                if(m>59) m%=10;
                if(f==12)
                {
                        if(h<=0) h=1;
                        else if(h>12)
                        {
                                if(h%10==0) h=10;
                                else h%=10;
                        }
                }
                else if(f==24)
                {
                        if(h>23)
                        {
                                h%=10;
                        }
                        if(h<0) h=0;
                }
                printf("%02d:%02d\n",h,m);
        }
        return 0;
}
