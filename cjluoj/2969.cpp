#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
        string s;
        int n;
        char c;
        while(cin>>n)
        {
                char ch=getchar();
                cin>>s;
                for(int i=0;i<s.length();i++)
                {
                        if(s[i]=='+') n*=2;
                        else if(s[i]=='/') n=1;
                        else if(s[i]=='-') n=0;
                        else if(s[i]=='*') n*=n;
                }
                cout<<n<<endl;
        }
        return 0;
}
