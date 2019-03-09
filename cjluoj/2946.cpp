#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        double n;
        int ans[32];
        while(cin>>n)
        {
                for(int i=0;i<32;i++)
                {
                        n*=2;
                        ans[i]=(int)n;
                        n-=(double)ans[i];
                }
                for(int i=0;i<32;i++)
                        cout<<ans[i];
                cout<<endl;
        }
        return 0;
}
