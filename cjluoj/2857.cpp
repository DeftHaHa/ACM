#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int a[]={5,10,15,20,25,30,35,40,45,50,55};
        int n;
        int i;
        while(cin>>n)
        {
                for(i=0;i<11;i++)
                {
                        if(a[i]==n)
                        {
                                cout<<i<<endl;
                                break;
                        }
                }
                if(i>=11) cout<<"no found"<<endl;
        }

        return 0;
}
