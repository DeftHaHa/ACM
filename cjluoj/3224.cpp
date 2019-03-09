#include<iostream>
using namespace std;
int main()
{
        int n;
        while(cin>>n)
        {
                if((n+1)%5==0) cout<<1<<endl;
                else cout<<0<<endl;
        }
        return 0;
}
