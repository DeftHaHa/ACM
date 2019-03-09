#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n[1005][1005];
int main()
{
        int a,b;
        int c,d;
        int tot;
        int i,j;
        memset(n,0,sizeof(n));
        while(cin>>a>>b)
        {
                tot=0;
                while(1)
                {
                        cin>>c>>d;
                        if(c==-1&&d==-1) break;
                        n[c][d]=1;
                        tot++;
                }
                cout<<"seat table:"<<endl;
                for(i=1;i<=a;i++)
                {
                        for(j=1;j<=b;j++)
                        {
                                printf("%3d",n[i][j]);
                        }
                        cout<<endl;
                }
                cout<<"the number of sold seats:"<<tot<<endl;
                printf("the rate of solde seats:%.2f%%\n",float(tot)/float(a*b)*100);
                memset(n,0,sizeof(n));
        }

        return 0;
}
