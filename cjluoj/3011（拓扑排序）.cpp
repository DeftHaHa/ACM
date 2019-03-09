#include<iostream>
#include<map>
#include<cstring>
#include<string>
using namespace std;
int main()
{
        map<string,int> m;
        int n;
        string s1,s2;
        int ind[10005];
        while(cin>>n)
        {
                m.clear();
                memset(ind,0,sizeof(ind));
                int tot=0;
                int u,v;
                while(n--)
                {
                        cin>>s1>>s2;
                        if(!m.count(s1))
                        {
                                m[s1]=++tot;
                                u=tot;
                        }
                        else u=m[s1];
                        if(!m.count(s2))
                        {
                                m[s2]=++tot;
                                v=tot;
                        }
                        else v=m[s2];
                        ind[v]++;
                }
                int flag=0;
                for(int i=1;i<=tot;i++)
                {
                        if(ind[i]==0) flag++;
                }
                if(flag==1) cout<<1<<endl;
                else cout<<0<<endl;
        }
        return 0;
}
