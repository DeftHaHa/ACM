#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
        int N;
        int n,ans;
        int t;
        while(cin>>N)
        {
                ans=0;
                t=N;
                while(N--)
                {
                        cin>>n;
                        if(n&1) ans++;
                }
                cout<<ans<<" "<<t-ans<<endl;
        }
        return 0;
}
