#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
        long long jc[27];
        jc[0]=1;
        jc[1]=1;
        for(long long i=2;i<27;i++)
        {
                jc[i]=jc[i-1]*i;
        }
        long long temp[27];
        temp[0]=1;
        temp[1]=25;
        for(long long i=2;i<=26;i++)
        {
                temp[i]=temp[i-1]*(26-i);
        }
        string s;
        long long ans;
        int T;
        cin>>T;
        while(T--)
        {
                cin>>s;
                int l=s.length();
                ans=1;
                for(int i=0;i<l;i++)
                {
                      ans+=(s[i]-'A')*temp[l-i-1];
                }

                cout<<ans<<endl;
        }
        return 0;
}
