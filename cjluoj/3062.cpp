#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        string s;
        while(cin>>s)
        {
                sort(s.begin(),s.end());
                do
                {
                        for(int i=0;i<s.length();i++) cout<<s[i];
                        cout<<endl;
                }while(next_permutation(s.begin(),s.end()));
        }
        return 0;
}
