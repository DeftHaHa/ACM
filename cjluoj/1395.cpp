#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
        int p[100];
        for(int i=2;i<100;i++) p[i]=i*i;
        for(int i;i<=100;i++)
        {
                bool flag=false;
                if(!flag)
                for(int j=i;j>=1;j--)
                {
                        if(i%j==0)
                        {
                                int k;
                                for(k=2;p[k]<=j;k++)
                                {
                                        if(j%p[k]==0) break;
                                }
                                if(p[k]>j)
                                {
                                        cout<<j<<endl;
                                        flag=true;
                                }
                        }
                }
        }
        return 0;
}
