#include<iostream>
#include<string>
using namespace std;
int main()
{

        string s;
        while(cin>>s)
        {
                int l=s.length();
                for(int i=0;i<l;i++)
                        if((l-i)&1) cout<<s[i];
                cout<<endl;
        }
        return 0;
}
