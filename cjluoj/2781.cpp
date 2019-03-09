#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
        int N;
        int b;
        int l,lmax;
        int i,j;
        int sum;
        int t[100],ans[100];
        while(cin>>N)
        {
                memset(ans,0,sizeof(ans));
                lmax=0;
                b=(int)sqrt(N);
                for(i=2;i<=b;i++)
                {
                        if(N%i==0)
                        {
                                l=0;
                                t[++l]=i;
                                sum=i;
                                for(j=i+1;j<=b;j++)
                                {
                                        if(N%j==0)
                                        {
                                                sum*=j;
                                                if(N%sum==0)
                                                        t[++l]=j;
                                                else break;
                                        }
                                        else break;
                                }
                                if(l>lmax)
                                {
                                        lmax=l;
                                        for(int k=1;k<=l;k++) ans[k]=t[k];
                                        memset(t,0,sizeof(t));
                                }

                        }
                }
                if(lmax==0)
                {
                        cout<<"1"<<endl<<N<<endl;
                        continue;
                }
                cout<<lmax<<endl;
                for(i=1;i<lmax;i++)
                        cout<<ans[i]<<"*";
                cout<<ans[i]<<endl;
        }
        return 0;
}
