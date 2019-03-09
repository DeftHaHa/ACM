#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
using namespace std;
int main()
{
        string s;
        int k;
        set<char> SET;
        int i;
        while(cin>>s)
        {
                cin>>k;
                if(k>s.size())
                {
                        cout<<"impossible"<<endl;
                        continue;
                }
                for(i=0;i<s.size();i++)
                {
                      SET.insert(s[i]);
                }
                int sum=SET.size();
                cout<<abs(k-sum)<<endl;
                SET.clear();
        }
        return 0;
}
