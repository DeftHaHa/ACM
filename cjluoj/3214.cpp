#include<iostream>
using namespace std;
int main()
{
        int n;
        while(cin>>n)
        {
                if(n==0) break;
                int ans=0;
                for(int i=1;i<=n-1;i++)
                {
                        int temp=i;
                        bool flag=false;
                        while(temp>0)
                        {
                                if(temp%10==7)
                                {
                                        flag=true;
                                        break;
                                }
                                temp/=10;
                        }
                        if(flag||i%7==0) {ans++;}
                }
                cout<<ans<<endl;

        }
        return 0;
}
