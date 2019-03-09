#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int layer[5];
int pack;
int inpack[25];
int ans,tot;
bool flag;
int salt[5][45];
int n;
void dfs()
{
        for(int i=1;i<=4;i++)
        {

                layer[i]++;
                pack++;
                int next=salt[i][layer[i]];
                inpack[next]++;
                if(pack>5||layer[i]>=n)
                {
                        pack--;
                        layer[i]--;
                        inpack[next]--;
                        return;
                }
                if(inpack[next]==2)
                {
                        tot++;
                        inpack[next]-=2;
                        pack-=2;
                        ans=max(ans,tot);
                        layer[i]--;
                        dfs();
                        continue;
                }

                dfs();

                layer[i]--;
                inpack[next]--;
                pack--;
        }
}
int main()
{
        int i,j;
        while(cin>>n)
        {
                if(n==0) break;
                for(j=1;j<=n;j++)
                        for(i=1;i<=4;i++)
                                cin>>salt[i][j];
                memset(inpack,0,sizeof(inpack));
                pack=0;
                memset(layer,0,sizeof(layer));
                ans=tot=0;
                dfs();
                cout<<ans<<endl;
        }
        return 0;
}
