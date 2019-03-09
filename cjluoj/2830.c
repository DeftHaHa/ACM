#include<stdio.h>
#include<math.h>
int main()
{
        float x,y;
        while(scanf("%f",&x)!=EOF)
        {
                if(x<-2) y=x*x-sin(x);
                else if(-2<=x&&x<=2) y=pow(2,x)+x;
                else y=sqrt(x*x+x+1);
                printf("%.2f\n",y);
        }
        return 0;
}
