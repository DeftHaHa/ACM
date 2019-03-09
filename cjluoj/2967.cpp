#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
        map<string,int> word;
        string s;
        int n;
        while(cin>>n)
        {
                if(n==0) break;
                int maxn=0;
                word.clear();
                while(n--)
                {
                        cin>>s;
                        maxn=max(maxn,++word[s]);
                }
                cout<<maxn<<endl;
        }
        return 0;
}
