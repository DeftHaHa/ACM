#include<iostream>
using namespace std;
int main()
{
        int n;
        while(cin>>n)
        {
                cout<<n*(n-1)*(n-2)/6<<endl;
        }
        return 0;
}
