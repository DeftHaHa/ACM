#include<iostream>
using namespace std;
int main()
{
        int T,k;
        cin>>T;
        while(T--)
        {
                bool flag;
                cin>>k;
                if(k<=4)
                {
                        if(k==2) flag=false;
                        else flag=true;
                }
                else
                {
                        k=(k-4)%7;
                        if(k==3||k==5) flag=false;
                        else flag=true;
                }
                if(flag) cout<<"win"<<endl;
                else cout<<"lose"<<endl;
        }
        return 0;
}
