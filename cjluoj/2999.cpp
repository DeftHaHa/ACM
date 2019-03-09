#include<algorithm>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
        int n;
        string s;
        map<string,int> m;
        while(cin>>n)
        {
                if(n==0) break;
                m.clear();
                while(n--)
                {
                     cin>>s;
                     m[s]++;
                }
                int ans=0;
                for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
                {
                        ans=max(ans,it->second);
                }
                cout<<ans<<endl;
        }
        return 0;
}
