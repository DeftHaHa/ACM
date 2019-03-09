#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
        string s;
        string temp,ans;
        int l;
        int i,j;
        int flag;
        while(cin>>l)
        {
                cin>>s;
                for(i=0;i<l;i++)
                {
                        flag=0;
                        if(s[i]=='o')
                        {

                                for(j=i;j<l;j+=2)
                                {
                                        if(s[j+1]=='g'&&s[j+2]=='o') flag=1;
                                        else break;
                                }
                                if(flag) i=j;
                        }
                        if(flag) ans+="***";
                        else ans+=s[i];
                }
                cout<<ans<<endl;
                ans.clear();
                s.clear();
        }
        return 0;
}
