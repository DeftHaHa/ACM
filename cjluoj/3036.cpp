#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int main()
{
        string binary[10]={"0","1","10","11","100","101","110","111","1000","1001"};
        string s;
        while(cin>>s)
        {
                for(int i=0;i<s.length();i++)
                {
                        if(s[i]=='1'||s[i]=='0') cout<<s[i];
                        else cout<<binary[s[i]-'0'];
                }
                cout<<endl;
        }
        return 0;
}
