#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
        string s1,s2;
        int begin1,begin2;
        int final1,final2;
        bool f1,f2,f3,f4;
        int i;
        while(cin>>s1>>s2)
        {
                begin1=begin2=-1;
                bool f1=f3=false;
                bool f2=f4=true;
                for(i=0;i<s1.length();i++)
                {
                        if(s1[i]!='0')
                        {
                                if(!f1)
                                {
                                        f1=true;
                                        begin1=i;
                                }
                        }
                        if(s1[i]!='0'&&s1[i]!='.') {f2=false;break;}
                }
                for(i=0;i<s2.length();i++)
                {
                        if(s2[i]!='0')
                        {
                                if(!f3)
                                {
                                        f3=true;
                                        begin2=i;
                                }
                        }
                        if(s2[i]!='0'&&s2[i]!='.') {f4=false;break;}
                }
                for(i=s1.length()-1;i>=0;i--)
                {
                        if(s1[i]!='0')
                        {
                                final1=i;
                                break;
                        }
                }
                for(i=s2.length()-1;i>=0;i--)
                {
                        if(s2[i]!='0')
                        {
                                final2=i;
                                break;
                        }
                }
                if(s1[final1]=='.') final1--;
                if(s2[final2]=='.') final2--;
                bool flag=true;
                if((begin1==-1&&begin2==-1)||(f2&&f4)) flag=true;
                else
                {
                        if(final1-begin1==final2-begin2)
                        {
                                for(i=0;i<=final1-begin1;i++)
                                {
                                        if(s1[begin1+i]!=s2[begin2+i])
                                        {
                                                flag=false;
                                                break;
                                        }
                                }
                        }
                        else flag=false;
                }
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
        }
        return 0;
}
