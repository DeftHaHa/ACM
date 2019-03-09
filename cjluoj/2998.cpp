#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
        double r,h;
        double pi=3.1415926535898;
        while(cin>>r>>h)
        {
                double ans=2*pi*r*r+2*pi*r*h;
                printf("%.3f\n",ans);
        }
        return 0;
}
