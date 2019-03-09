#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp(const float &a,const float &b)
{
        return a>b;
}
int main()
{
        float a[10005];
        int n;
        int i;
        char c;
        memset(a,0,sizeof(0));
        while(cin>>n)
        {
                for(i=0;i<n;i++)
                        cin>>a[i];
                cin>>c;
                if(c=='u'||c=='U') sort(a,a+n);
                else if(c=='d'||c=='D') sort(a,a+n,cmp);
                for(i=0;i<n;i++)
                {
                        printf("%.2f",a[i]);
                        if(i!=n) cout<<' ';
                }
                cout<<endl<<endl;
                memset(a,0,sizeof(0));
        }

        return 0;
}
