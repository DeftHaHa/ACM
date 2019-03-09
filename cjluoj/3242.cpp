#include<cstring>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
        int T,c=1;
        int num[8];
        int i;
        string s;
        char a,b;
        cin>>T;
        while(T--)
        {
                for(i=0;i<8;i++) cin>>num[i];
                cout<<"Case "<<c++<<':'<<endl;
                while(1)
                {
                        cin>>s;
                        if(s=="READ")
                        {
                              cin>>a;
                              cout<<num[a-'a']<<endl;
                        }
                        else if(s=="ADD")
                        {
                                cin>>a>>b;
                                num[a-'a']=num[a-'a']+num[b-'a'];
                        }
                        else if(s=="SUB")
                        {
                                cin>>a>>b;
                                num[a-'a']=num[a-'a']-num[b-'a'];
                        }
                        else if(s=="MOVE")
                        {
                                cin>>a>>b;
                                num[a-'a']=num[b-'a'];
                        }
                        else if(s=="STOP") break;

                }
        }
        return 0;
}
