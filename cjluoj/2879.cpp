#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        long long n[3];
        long long ans;
        while(cin>>n[0]>>n[1]>>n[2])
        {
                sort(n,n+3);
                ans=0;
                n[2]-=1;
                if(n[2]>=n[0]) ans+=n[2]-n[0];
                if(n[2]>=n[1]) ans+=n[2]-n[1];
                cout<<ans<<endl;
        }
        return 0;
}
