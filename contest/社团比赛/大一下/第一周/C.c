#include<stdio.h>
#include<math.h>
double max(double a,double b)
{
        if(a>b) return a;
        else return b;
}
int main()
{
        double r_1,r_2;
        double ans;
        while(1)
        {
                scanf("%lf%lf",&r_1,&r_2);
                ans=sqrt(r_1*r_2)*2+r_1+r_2;
                if(r_1==0&&r_2==0) break;
                else if(max(r_1,r_2)*2>=ans)
                        printf("%.2lf\n",max(r_1,r_2)*2);
                else
                {
                        printf("%.2lf\n",ans);
                }
        }
        return 0;
}
