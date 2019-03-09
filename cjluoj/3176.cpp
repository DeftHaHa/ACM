#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
        return b==0?a:gcd(b,a%b);
}
int main()
{
        int T;
        long long p;
        long long v[7],a[7];
        cin>>T;
        int i;
        while(T--)
        {
                cin>>p;
                for(i=0;i<7;i++) cin>>v[i];
                for(i=0;i<7;i++) cin>>a[i];
                long long sum=0;
                for(i=0;i<7;i++) sum+=v[i]*a[i];
                p=sum-p;
                long long GCD=gcd(p,sum);
                long long ans1=p/GCD;
                long long ans2=sum/GCD;
                cout<<ans1<<'/'<<ans2<<endl;
                if(ans1<ans2/2) cout<<"No! The KFC is kidding me!"<<endl;
                else cout<<"Yes! The real half-price!"<<endl;
        }
        return 0;
}
