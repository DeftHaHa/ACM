#include<iostream>
#include<string>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;
set<string> Set;
int main()
{
        string s,buf;
        while(cin>>s)
        {
                for(int i=0;i<s.length();i++)
                        if(isalpha(s[i])) s[i]=tolower(s[i]);
                        else s[i]=' ';
                stringstream ss(s);             ///字符串流
                while(ss>>buf)
                {
                        if(!Set.count(buf))
                                Set.insert(buf);
                }
        }
        for(set<string>::iterator it=Set.begin();it!=Set.end();it++)
                cout<<*it<<endl;
        return 0;
}
