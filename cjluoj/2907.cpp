#include<iostream>
#include<string>
using namespace std;
int main()
{
        int n;
        string s;
        int ans;
        while(cin>>n)
        {
                while(n--)
                {
                        cin>>s;
                        ans=0;
                        for(int i=0;i<s.size();i++)
                        {
                                if(s[i]>='0'&&s[i]<='9') ans++;
                        }
                        cout<<ans<<endl;
                }
        }
        return 0;
}
