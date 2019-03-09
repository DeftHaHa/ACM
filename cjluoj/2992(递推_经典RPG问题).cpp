#include<iostream>
using namespace std;
int main()
{
        int i,n;
        long long a[55]={3,6,6};
        for (i=3;i<55;i++)
                a[i]=a[i-1]+2*a[i-2];
        while(cin>>n)
        {
                if(n==0) cout<<0<<endl;
                else cout<<a[n-1]<<endl;
        }
    return 0;
}
