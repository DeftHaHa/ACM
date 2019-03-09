#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
        string s;
        int i;
        int n,t;
        int ans;
        while(cin>>s)
        {
                ans=0;
                s='a'+s;
                for(i=1;i<s.size();i++)
                {
                        t=s[i-1]-'a';
                        n=s[i]-'a';
                        if(t<n)
                        {

                                ans+=min(abs(t+26-n),abs(n-t));
                        }
                        else
                        {

                                ans+=min(abs(n+26-t),abs(n-t));
                        }
                }
                cout<<ans<<endl;
                s.clear();
        }
        return 0;
}
