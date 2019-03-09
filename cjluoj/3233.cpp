#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
        string s;
        int num[105];
        int ans[105];
        int i,j;
        memset(num,-1,sizeof(num));
        while(cin>>s)
        {
                for(i=0;i<s.length();i++)
                {
                        if(s[i]=='5') num[i]=-1;
                        else num[i]=s[i]-'0';
                }
                int tot=0;
                for(i=0;i<s.length();i++)
                {
                        if(num[i]!=-1)
                        {
                                for(j=i;j<=s.length();j++)
                                {
                                        if(num[j]==-1) break;
                                }
                                int temp=0;
                                int ten=1;
                                for(int k=j-1;k>=i;k--)
                                {
                                        temp+=num[k]*ten;
                                        ten*=10;
                                }
                                ans[tot++]=temp;
                                i=j;
                        }

                }
                sort(ans,ans+tot);
                cout<<ans[0];
                for(i=1;i<tot;i++) cout<<' '<<ans[i];
                cout<<endl;
                memset(num,-1,sizeof(num));
        }
        return 0;
}
