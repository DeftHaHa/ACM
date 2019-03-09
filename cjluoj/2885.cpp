#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
        int l;
        int maxl,tl;
        int tot;
        string s;
        int i,j;
        while(cin>>l)
        {
                cin>>s;
                maxl=0;tot=0;
                for( i=0;i<l;i++)
                {
                        if(s[i]=='(')
                        {
                                for(j=i+1;j<l;j++)
                                {
                                        if(isalpha(s[j])&&!isalpha(s[j+1])) tot++;
                                        if(s[j]!=')') break;
                                }
                                i=j+1;
                        }
                        else if(s[i]=='_')
                        {
                                continue;
                        }
                        else
                        {
                                tl=0;
                                for(j=i;j<l;j++)
                                {
                                        tl++;
                                        if(!isalpha(s[j])) break;
                                }
                                if(tl>maxl) maxl=tl;
                                i=j+1;
                        }
                }
                cout<<maxl<<' '<<tot<<endl;
        }
        return 0;
}
