#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
        string s1,s2;
        while(cin>>s1>>s2)
        {
                sort(s1.begin(),s1.end());
                sort(s2.begin(),s2.end());
                int d=s1[0]-s2[0];
                bool flag=true;
                for(int i=1;i<s1.length();i++)
                        if(s1[i]-s2[i]!=d)
                        {
                                flag=false;
                                break;
                        }
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
        }
        return 0;
}
