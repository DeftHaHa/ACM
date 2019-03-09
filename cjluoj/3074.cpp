#include<iostream>
using namespace std;
int main()
{
        int T;
        int n;
        int a[1005];
        cin>>T;
        while(T--)
        {
                cin>>n;
                for(int i=1;i<=n;i++) cin>>a[i];
                int ans=0;
                for(int i=1;i<=n-1;i++)
                {
                        for(int j=i+1;j<=n;j++)
                        {
                                if(a[j]<a[i]) ans++;
                        }
                }
                cout<<ans<<endl;
        }
        return 0;
}
