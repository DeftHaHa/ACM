#include<iostream>
using namespace std;
int main()
{
        int a,b;
        while(cin>>a>>b)
        {
                if(a%(b+1)!=0) cout<<"clinic win"<<endl;
                else cout<<"enidecs win"<<endl;
        }
        return 0;
}
