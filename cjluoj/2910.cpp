#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
        int n,c=1;
        int a[1005];
        int numa[10],numb[10];
        int x;
        int i;
        while(cin>>n)
        {
                if(n==0) break;
                memset(numa,0,sizeof(numa));
                for(i=0;i<n;i++)
                {
                        cin>>a[i];
                        numa[a[i]]++;
                }
                cout<<"Game "<<c++<<':'<<endl;
                while(1)
                {
                        int ans1=0,ans2=0;
                        memset(numb,0,sizeof(numb));
                        for(i=0;i<n;i++)
                        {
                                cin>>x;
                                if(x==a[i]) ans1++;
                                numb[x]++;
                        }
                        if(x==0) break;
                        for(int i=1;i<=9;i++)
                        {
                                ans2+=min(numa[i],numb[i]);
                        }
                        printf("    (%d,%d)\n",ans1,ans2-ans1);
                }
        }
        return 0;
}
