#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double yuxian(double a,double b,double c)
{
        return (a*a+b*b-c*c)/(2*a*b);
}
int main()
{
        double xa,xb,xc,ya,yb,yc;
        double a,b,c;
        double co[3];
        double angle;
        while(scanf("%lf%lf",&xa,&ya)!=EOF)
        {
                scanf("%lf%lf%lf%lf",&xb,&yb,&xc,&yc);
                a=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
                b=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
                c=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
                memset(co,0,sizeof(co));
                co[0]=yuxian(b,c,a);
                co[1]=yuxian(a,c,b);
                co[2]=yuxian(a,b,c);
                sort(co,co+3);
                angle=acos(co[0])*180/3.1415926;
                printf("%.2f\n",angle);
        }
        return 0;
}
