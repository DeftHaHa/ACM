#include<iostream>
using namespace std;
int main()
{
        int n;
        while(cin>>n)
        {
                int ans=0;
                while(n)
                {
                        n=n/5;
                        ans+=n;
                }
                cout<<ans<<endl;
        }
        return 0;
}
