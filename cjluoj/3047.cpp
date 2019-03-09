#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
        bool num[10005];
        memset(num,false,sizeof(num));
        int n;
        int i;
        int j,k;
        int tot,a[6];
        for(i=0;i<=9;i++) num[i]=true;
        for(i=11;i<=10000;i++)
        {
                tot=0;
                int temp=i;
                while(temp)
                {
                        a[++tot]=temp%10;
                        temp/=10;
                }
                bool flag=true;
                for(j=1,k=tot;j<=k;j++,k--)
                {
                        if(a[j]!=a[k])
                        {
                                flag=false;
                                break;
                        }
                }
                if(flag) num[i]=true;
        }
        while(cin>>n)
        {
                for(i=n+1;i<=10000;i++)
                {
                        if(num[i])
                        {
                                cout<<i<<endl;
                                break;
                        }
                }
        }
        return 0;
}
