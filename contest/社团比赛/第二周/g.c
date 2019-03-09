#include<stdio.h>
#include<math.h>
int main()
{
        int t;
        double r,n,pi;
        pi=acos(-1.0);
        scanf("%d",&n);
        while(t--)
        {
                scanf("%lf%lf",&r,&n);
                printf("%.3lf\n",n*r*cos(pi/n)*r*sin(pi/n));
        }
        return 0;
}
