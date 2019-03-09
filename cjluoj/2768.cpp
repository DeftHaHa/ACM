#include<iostream>
#include<cstring>
using namespace std;
long long mod=1e9+7;
long long jc(long long n)
{
        long long ans=1;
        long long i;
        for(i=2;i<=n;i++)
        {
                ans*=i;
                if(ans>mod) ans%=mod;
        }
        return ans%mod;
}
long long zuhe(long long n,long long m)
{
        if(n==0||m==n) return 1;
        long long i;
        long long ans=1;
        for(i=n;i<=m;i++)
        {
                ans*=i;
                if(ans>mod) ans%mod;
        }
        return ans/(jc(m-n))%mod;
}
int main()
{
        long long n;
        long long num[10];
        long long i;
        long long tot,totkind;
        long long ans;
        while(cin>>n)
        {
                for(i=0;i<10;i++)
                        cin>>num[i];
                tot=0;
                totkind=0;
                for(i=0;i<10;i++)
                {
                        tot+=num[i];
                        if(num[i]>0&&i!=0) totkind++;
                }
                if(tot>n)
                {
                        cout<<0<<endl;
                        continue;
                }
                else if(n==tot)
                {
                        ans=1;
                        ans=(tot-num[0])*jc(tot-1)%mod;
                        cout<<ans<<endl;
                }
                else
                {
                        ans=1;


                                ans=ans*(9-totkind)*zuhe(tot,n-tot)*jc(tot);
                                for(i=0;i<n-1-tot;i++)
                                        ans=ans*10%mod;
                                long long ansb=1;
                                ansb=ansb*totkind*zuhe(tot-1,n-1)*jc(tot-1);
                                for(i=0;i<n-1-(tot-1);i++)
                                        ansb=ansb*10%mod;
                                ans+=ansb;


                        cout<<ans%mod<<endl;
                }
        }
        return 0;
}
