#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
        int n,m;
        int a[105];
        int year,month,day;
        int year_1,month_1,day_1;
        int year_2,month_2,day_2;
        int inmax,inmin;
        int ans;
        char ch[5];
        int i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                scanf("%s %d-%d-%d",ch,&year,&month,&day);
                a[i]=year*10000+month*100+day;
        }
        scanf("%d",&m);
        while(m--)
        {
                scanf("%d-%d-%d%d-%d-%d",&year_1,&month_1,&day_1,&year_2,&month_2,&day_2);
                inmin=year_1*10000+month_1*100+day_1;
                inmax=year_2*10000+month_2*100+day_2;
                ans=0;
                for(i=0;i<n;i++)
                {
                        if(a[i]>=inmin&&a[i]<=inmax) ans++;
                }
                printf("%d\n",ans);
        }
        return 0;
}
