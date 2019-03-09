#include<iostream>
using namespace std;
int main()
{
        int n;
        int step;
        while(cin>>n)
        {
                step=0;
                while(n!=1)
                {
                        if(n&1) n=(3*n+1)/2;
                        else n/=2;
                        step++;
                }
                cout<<step<<endl;
        }
        return 0;
}
