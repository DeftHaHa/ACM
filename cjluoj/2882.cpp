#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
        string week[7]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
        string a,b;
        int f,s;
        int t;
        while(cin>>a>>b)
        {
                for(int i=0;i<7;i++)
                {
                        if(week[i]==a) f=i;
                        if(week[i]==b) s=i;
                }
                if(f<=s) t=s-f;
                else t=s+7-f;
                if(t==2||t==3||t==0)
                        cout<<"YES"<<endl;
                else
                        cout<<"NO"<<endl;
        }
        return 0;
}
