#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        string s;
        int N;
        cin>>N;
        while(N--)
        {
                cin>>s;
                int ans=0;
                for(int i=0;i<s.length();i++)
                {
                        if(s[i]=='H')
                                if(s[i+1]=='a') ans++;
                }
                s.clear();
                cout<<ans<<endl;
        }
        return 0;
}
