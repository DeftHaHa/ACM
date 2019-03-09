#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int a[45];
        int n;
        int i;
        a[1]=1;
        a[2]=1;
        for(i=3;i<45;i++)
                a[i]=a[i-1]+a[i-2];
        while(cin>>n)
        {
                for(i=1;i<=n;i++)
                {
                        cout<<a[i];
                        if((i-5)%5==0&&i!=n) cout<<endl;
                        else if(i!=n) cout<<' ';
                }
                cout<<endl;
        }

        return 0;
}
