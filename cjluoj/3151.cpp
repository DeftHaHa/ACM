#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        string s;
        int i,start;
        int id[27];
        while(cin>>s)
        {
                start=1;
                int ans=0;
                memset(id,0,sizeof(id));
                for(i=1;i<=s.length();i++)
                {
                        if(id[s[i-1]-'a']<start) ans=max(ans,i-start+1);
                        else start=id[s[i-1]-'a']+1;
                        id[s[i-1]-'a']=i;
                }
                cout<<ans<<endl;
        }
        return 0;
}
