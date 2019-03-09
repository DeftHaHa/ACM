#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        int l[10005];
        int n,k;
        int i,j;
        int last;
        while(cin>>n>>k)
        {
                for(i=1;i<=n;i++)
                        l[i]=1;
                for(i=2;i<=k;i++)
                {
                        for(j=i;j<=n;j+=i)
                                l[j]*=-1;
                }
                for(i=n;i>=0;i--)
                {
                        if(l[i]==1)
                        {
                                last=i;
                                break;
                        }
                }
                for(i=1;i<=n;i++)
                {
                        if(l[i]==1)
                        {
                                cout<<i;
                                if(i<n) cout<<' ';
                        }
                }
                cout<<endl;
        }
        return 0;
}
