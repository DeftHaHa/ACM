#include<stdio.h>
#include<math.h>
int main()
{
        int w;
        int s;
        int x,y;
        int s_1;
        while(1)
        {
                scanf("%d%d%d%d",&w,&s,&x,&y);
                if(w==0&&s==0&&x==0&&y==0) break;
                if(s==x) printf("%d\n",s);
                else if(x>s)
                {
                        s_1=2*x-s;
                        if((s_1)<=w) printf("%d\n",s_1);
                        else printf("%d\n",2*w-s_1);
                }
                else if(x<s)
                {
                        printf ("%d\n",abs(2*x-s));
                }
        }
        return 0;
}
