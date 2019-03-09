#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        bool prime[1005];
        int i,j;
        int T;
        memset(prime,true,sizeof(prime));
        for(i=2;i<1005;i++)
        {
                if(prime[i])
                {
                        for(j=i*i;j<1005;j+=i)
                        {
                                prime[j]=false;
                        }
                }
        }
        int a,b;
        cin>>T;
        while(T--)
        {
                cin>>a>>b;
                int ans=0;
                for(i=a;i<=b;i++)
                        if(prime[i]) ans++;
                cout<<ans<<endl;
        }
        return 0;
}
