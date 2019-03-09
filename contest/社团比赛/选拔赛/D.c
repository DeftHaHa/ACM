#include<stdio.h>
int main()
{
        int n,m;
        int i;
        char ch;
        int year[100],month[100],day[100];
        int a,b,c,a1,b1,c1;
        int ans;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                scanf("%s %d-%d-%d",&ch,&year[i],&month[i],&day[i]);
        }
        scanf("%d",&m);
        while(m--)
        {
                scanf("%d-%d-%d",&a,&b,&c);
                scanf("%d-%d-%d",&a1,&b1,&c1);
                ans=0;
                for(i=0;i<n;i++)
                {
                        if(year[i]>a&&year[i]<a1)
                        {
                                ans++;
                        }
                        else if(year[i]==a&&year[i]==a1)
                        {
                                if(month[i]>b&&month[i]<b1) ans++;
                                else if(month[i]==b&&month[i]<b1&&day[i]>=c) ans++;
                                else if(month[i]>b&&month[i]==b1&&day[i]<=c1)   ans++;
                                else if(month[i]==b&&month[i]==b1&&day[i]>=c&&day[i]<=c1) ans++;
                        }
                        else if(year[i]==a&&year[i]<a1)
                        {
                                if(month[i]>b) ans++;
                                else if(month[i]==b&&day[i]>=c) ans++;
                        }
                        else if(year[i]>a&&year[i]==a1)
                        {
                                if(month[i]<b1) ans++;
                                else if(month[i]==b1&&day[i]<=c1) ans++;
                        }
                }
                printf("%d\n",ans);
        }

        return 0;
}
