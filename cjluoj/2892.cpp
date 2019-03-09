#include<iostream>
#include<string>
using namespace std;
int main()
{
        string s;
        int ans;
        while(getline(cin,s))
        {
                ans=0;
                for(int i=0;i<s.size();i++)
                {
                        if(s[i]==' '||s[i]==',')
                                ans++;
                        while(s[i]==' '||s[i]==',')
                        {
                                i++;
                        }
                }

                cout<<ans+1<<endl;
        }
        return 0;
}
