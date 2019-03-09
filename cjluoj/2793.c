#include<stdio.h>
int main()
{
        int h,m;
        int i;
        while(scanf("%d:%d",&h,&m)!=EOF)
        {
                if((h>=0&&h<12)||(h==12&&m==0))
                        printf("Only %02d:%02d.  Too early to Dang.\n",h,m);
                else
                {
                        h=h-12;
                        if(m>0) h+=1;
                        for(i=0;i<h;i++)
                                printf("Dang");
                        printf("\n");
                }
        }
        return 0;
}
