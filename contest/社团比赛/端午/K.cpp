#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
struct wuya
        {
                double x;
                double f;
                int flag;
        }w[15];
int main()
{
        int n;
        double l,v;
        double t;
        int i,j;
        int total;
        int ok;
        while(scanf("%d%lf%lf",&n,&l,&v)!=EOF)
        {
                memset(w,0,sizeof(w));
                total=0;
                for(i=0;i<n;i++)
                        scanf("%lf%lf",&w[i].x,&w[i].f);
                ok=1;
                t=0;
                while(ok)
                {
                        t+=0.000001;
                        for(i=0;i<n;i++)
                                w[i].x+=w[i].f*v*0.000001;
                        for(i=0;i<n;i++)
                        {
                                if(w[i].x>=l||w[i].x<=0&&w[i].flag!=1)
                                {
                                        w[i].flag=1;
                                        total++;
                                        if(total==1) printf("%.6f\n",t);
                                        else if(total==n)
                                        {
                                                printf("%.6f\n",t);
                                                ok=0;
                                        }
                                }
                                for(j=i+1;j<n;j++)
                                {
                                        if(w[i].x==w[j].x)
                                        {
                                                w[i].f*=-1;
                                                w[j].f*=-1;
                                        }
                                }
                        }
                }
        }
        return 0;
}
