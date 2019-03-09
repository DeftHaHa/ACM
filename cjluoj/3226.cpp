#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
        string s;
        while(cin>>s)
        {
                for(int i=0;i<s.length();i++)
                        if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
                cout<<s<<endl;
        }
        return 0;
}
