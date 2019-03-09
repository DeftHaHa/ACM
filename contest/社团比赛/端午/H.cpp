#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
double dis(double xa,double ya,double xb,double yb,double xc,double yc)
{
        return fabs((xc-xa)*(ya-yb)-(yc-ya)*(xa-xb))/sqrt((ya-yb)*(ya-yb)+(xa-xb)*(xa-xb));
}
int main()
{
        double da,db;
        double xa1,xa2,ya1,ya2,xb1,xb2,yb1,yb2,xc,yc;
        double da1,da2,db1,db2;
        while(scanf("%lf%lf",&xa1,&ya1)!=EOF)
        {
                scanf("%lf%lf",&xa2,&ya2);
                scanf("%lf%lf",&xb1,&yb1);
                scanf("%lf%lf",&xb2,&yb2);
                scanf("%lf%lf",&xc,&yc);
                da=dis(xa1,ya1,xa2,ya2,xc,yc);
                db=dis(xb1,yb1,xb2,yb2,xc,yc);
                if(da<db) printf("uTOPia\n");
                else if(da>db) printf("Archimedes\n");
                else if(da==db) printf("Equal\n");
        }
        return 0;
}
