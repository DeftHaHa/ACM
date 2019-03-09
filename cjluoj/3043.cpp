#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
        string s1,s2;
        while(cin>>s1>>s2)
        {
                int ans=0;
                for(int i=0;i<s1.length();i++)
                        ans+=s1[i]-'0';
                for(int i=0;i<s2.length();i++)
                        ans+=s2[i]-'0';
                cout<<ans<<endl;
        }
        return 0;
}
