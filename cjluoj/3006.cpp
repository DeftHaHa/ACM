#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
        int n,m,p;
        int r,c;
        int row[100005];
        while(scanf("%d%d%d",&n,&m,&p)!=EOF)
        {
                if(n==0&&m==0&p==0) break;
                for(int i=1;i<=p;i++)
                {
                        cin>>r>>c;
                        row[i]=r;
                }
                sort(row+1,row+p+1);
                int mid=p/2;
                int t=row[mid];
                long long ans=0;
                for(int i=1;i<=mid;i++)
                        ans+=t-row[i];
                for(int i=mid;i<=p;i++)
                        ans+=row[i]-t;
                cout<<ans<<endl;
                printf("%d\n",ans);
        }
        return 0;
}
