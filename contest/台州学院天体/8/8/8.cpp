#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
        int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        char M[]={'1','0','X','9','8','7','6','5','4','3','2'};
        int N;
        string s;
        while(cin>>N)
        {
                int T=N;
                int tot=0;
                while(T--)
                {
                        cin>>s;
                        bool flag=true;
                        int sum=0;
                        for(int i=0;i<17;i++)
                        {
                                if(s[i]-'0'>9||s[i]-'0'<0)
                                {
                                        flag=false;
                                        break;
                                }
                                else
                                {
                                        sum+=(s[i]-'0')*w[i];
                                }
                        }
                        if(M[sum%11]!=s[17]) flag=false;
                        if(!flag)
                                cout<<s<<endl;
                        else tot++;
                }
                if(tot==N) cout<<"All passed"<<endl;
        }
        return 0;
}
