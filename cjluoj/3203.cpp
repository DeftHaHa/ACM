#include<iostream>
using namespace std;
int main()
{
        int n,m;
        while(cin>>n>>m)
        {
                int ans1=(4*n-m)/2;
                int ans2=n-ans1;
                if(m%2==1||ans1<0||ans2<0) cout<<"no answer"<<endl;
                else cout<<ans1<<' '<<ans2<<endl;
        }
        return 0;
}
