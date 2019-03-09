#include<queue>
#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
        string s;
        int ans;
        priority_queue<int,vector<int> > q;
        while(cin>>s)
        {
                if(s[0]=='N')
                {
                        cin>>s;
                        ans=q.top();
                        q.pop();
                        printf("%d\n",ans);
                }
                else
                {
                        int num=0;
                        for(int i=0;i<s.length();i++)
                        {
                                num*=10;
                                num+=s[i]-'0';
                        }
                        q.push(num);
                }
        }
        return 0;
}
