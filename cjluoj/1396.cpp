#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
        int n;
        int a[100005],p[100005];
        int pmin;
        int ans;
        int i;
        while(cin>>n)
        {

                for(i=0;i<n;i++)
                        cin>>a[i]>>p[i];
                ans=0;
                pmin=p[0];
                for(i=0;i<n;i++)
                {
                        if(p[i]<pmin) pmin=p[i];
                        ans+=a[i]*pmin;
                }
                cout<<ans<<endl;
        }
        return 0;
}
