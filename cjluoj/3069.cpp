#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        int n;
        int left=1,right=100;
        bool p[105];
        string s;
        int i;
        memset(p,true,sizeof(p));
        while(scanf("%d",&n)!=EOF)
        {

                cin>>s;cin>>s;
                if(s[0]=='l')
                {
                        for(i=left;i<=n;i++) p[i]=false;
                        left=n+1;
                }
                else if(s[0]=='h')
                {
                        for(i=n;i<=right;i++) p[i]=false;
                        right=n-1;
                }
                else if(s[0]=='o')
                {
                        if(p[n]) cout<<"Wade may be honest"<<endl;
                        else cout<<"Wade is dishonest"<<endl;
                        memset(p,true,sizeof(p));
                        left=1;
                        right=100;
                }
        }
        return 0;
}
