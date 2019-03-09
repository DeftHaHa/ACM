#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
        set<char> SET;
        string s1,s2;
        bool vis[26];
        bool List[26];
        int tot;
        int i;
        while(cin>>s1>>s2)
        {
                SET.clear();

                memset(List,false,sizeof(List));
                tot=0;
                for(i=0;i<s2.length;i++)
                {
                        if(!List[s2[i]-'a'])
                        {
                                List[s2[i]-'a']=true;
                                tot++;
                        }
                }
                memset(vis,false,sizeof(vis));
                for(i=0;i<s1.length();i++)
                {
                        if(!vis[s1[i]-'a'])
                        {
                                vis[s1[i]-'a']=true;
                                if(List[s])
                        }
                }
        }
        return 0;
}
