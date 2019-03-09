#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
        string s;
        int i;
        int temp,ans;
        while(cin>>s)
        {
                temp=-1;
                ans=0;
                for(i=0;i<s.size();i++)
                {
                        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
                        {

                                if(i-temp>ans) ans=i-temp;
                                temp=i;
                        }
                }
                if(s.size()-temp>ans) ans=s.size()-temp;
                cout<<ans<<endl;
                s.clear();
        }
        return 0;
}
