#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
        int k,r;
        int tot,sum;
        while(cin>>k>>r)
        {
                tot=1;
                sum=k;
                while(1)
                {
                        sum%=10;
                        if(sum==r||sum==0)
                        {
                                cout<<tot<<endl;
                                break;
                        }
                        sum+=k;
                        tot++;
                }
        }
        return 0;
}
