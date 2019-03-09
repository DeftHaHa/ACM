#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
        string s;
        int n;
        int i;
        while(cin>>s)
        {
                if(s[0]=='0') break;
                cout<<s<<endl;
                s.clear();
        }
        return 0;
}
