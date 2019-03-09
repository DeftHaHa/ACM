#include<string>
#include<iostream>
using namespace std;
int main()
{
        int N;
        string s;
        while(cin>>N)
        {
                cin>>s;
                int ans=0;
                for(int i=0;i<s.size();i++)
                        if(s[i]=='1') ans++;
                cout<<ans<<endl;
        }
        return 0;
}
