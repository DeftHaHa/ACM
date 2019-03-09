#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
int main()
{
        double c,d;
        double x=1e-9;
        while(cin>>d>>c)
        {
                if(d*0.3-(c*0.1+3.0)<x) cout<<"Dad win!";
                else cout<<"Child win!"<<endl;
        }
        return 0;
}
