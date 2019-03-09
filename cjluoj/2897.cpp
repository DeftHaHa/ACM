#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
        string s;
        int i;
        while(cin>>s)
        {
                sort(s.begin(),s.end());
                cout<<s<<endl;
                s.clear();
        }
        return 0;
}
