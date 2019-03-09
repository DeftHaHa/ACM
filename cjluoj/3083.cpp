#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
        string s;
        int c=0;
        int ans[26];
        while(getline(cin,s))
        {
                memset(ans,0,sizeof(ans));
                for(int i=0;i<s.length();i++)
                {
                        if(s[i]!=' ') ans[s[i]-'a']++;
                }
                cout<<"Case "<<++c<<':'<<endl;
                bool flag=false;
                for(int i=0;i<26;i++)
                {
                        if(ans[i]>0)
                        {
                                if(!flag)
                                {
                                        printf("%c:%d",'a'+i,ans[i]);
                                        flag=true;
                                }
                                else printf(" %c:%d",'a'+i,ans[i]);
                        }
                }
                cout<<endl;
        }
        return 0;
}
