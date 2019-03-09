#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        float t[100005];
        int n,s;
        float sum;
        int i;
        float wt[10005],tr[10005];
        while(scanf("%d%d",&n,&s)!=EOF)
        {
                for(i=0;i<n;i++)
                {
                        scanf("%f",&t[i]);
                }
                sort(t,t+n);
                int j=0;
                i=0;
                memset(wt,0,sizeof(wt));
                memset(tr,0,sizeof(tr));
                while(i<n)
                {
                        wt[j]+=t[i];
                        tr[j]+=wt[j];
                        i++;
                        j++;
                        if(j==s) j=0;

                }
                sum=0;
                for(i=0;i<s;i++) sum+=tr[i];
                printf("%.3f\n",sum/n);
        }
        return 0;
}
