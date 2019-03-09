#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        int n;
        while(1)
        {
                cin>>n;
                if(n==-1) break;
                else if(n<0) cout<<"input<0"<<endl;
                else
                {
                        int ans=0;
                        while(n>0)
                        {
                                n/=10;
                                ans++;
                        }
                        cout<<ans<<endl;
                }
        }
        return 0;
}
