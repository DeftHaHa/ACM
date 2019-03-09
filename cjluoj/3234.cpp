#include<iostream>
using namespace std;
int gcd(int a,int b)
{
        return b==0?a:gcd(b,a%b);
}
int main()
{
        int n;
        int a,b,c;
        cin>>n;
        while(n--)
        {
                cin>>a>>b>>c;
                if(c%gcd(a,b)==0) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
        }
        return 0;
}
