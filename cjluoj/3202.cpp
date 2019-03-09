#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
        string s1,s2;
        int ans[105][105];
        while(cin>>s1>>s2)
        {
                memset(ans,0,sizeof(ans));
                int l1=s1.length(),l2=s2.length();
                for(int i=1;i<=l1;i++)
                {
                        for(int j=1;j<=l2;j++)
                        {
                                if(s1[i-1]==s2[j-1]) ans[i][j]=ans[i-1][j-1]+1;
                                else ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
                        }
                }
                cout<<l1+l2-ans[l1][l2]<<endl;
        }
        return 0;
}
