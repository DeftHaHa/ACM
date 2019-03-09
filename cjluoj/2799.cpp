#include<iostream>
using namespace std;
int main()
{
        int n;
        while(cin>>n)
        {
                if(n==5) cout<<"7"<<endl;
                else cout<<(n+2)%7<<endl;
        }
        return 0;
}
