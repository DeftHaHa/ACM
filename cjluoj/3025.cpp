#include<iostream>
using namespace std;
int main()
{
        int a[6],i,T;
        cin>>T;
        while(T--)
        {
                for(i=0;i<6;i++) cin>>a[i];
                int C=(a[2]+a[5])%60;
                int B=(a[1]+a[4]+(a[2]+a[5])/60)%60;
                int A=a[0]+a[3]+(a[1]+a[4]+(a[2]+a[5])/60)/60;
                cout<<A<<' '<<B<<' '<<C<<endl;
        }
        return 0;
}
