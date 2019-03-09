#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int trie[100000][31];
string ans;
int main()
{
        int cnt[100000];
        int tot;
        string s;
        int T;
        cin>>T;
        while(T--)
        {
                int N;
                memset(trie,-1,sizeof(trie));
                memset(cnt,0,sizeof(cnt));
                cin>>N;
                char ch=getchar();
                int anst=0;
                tot=0;
                int n=N;
                bool flag=true;
                while(N--)
                {
                        cin>>s;
                        int p=0;
                        if(flag)
                        {
                                for(int i=0;i<s.length();i++)
                                {
                                        int k;
                                        if(s[i]=='.') k=27;
                                        else if(s[i]=='/') k=28;
                                        else if(s[i]==':') k=29;
                                        else if(s[i]=='\n') k=30;
                                        else k=s[i]-'a';
                                        if(trie[p][k]==-1)
                                        {
                                                trie[p][k]=++tot;
                                        }
                                        p=trie[p][k];
                                }
                                cnt[p]++;
                        }
                        if(cnt[p]>n/2&&flag)
                        {
                                ans=s;
                                flag=false;
                        }
                }
                cout<<ans<<endl;

        }
        return 0;
}
