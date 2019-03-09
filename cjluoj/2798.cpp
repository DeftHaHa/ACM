#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        char s[10005];
        int g,p,l,t;
        int i;
        memset(s,0,sizeof(s));
        while(scanf("%s",s)!=EOF)
        {
                g=p=l=t=0;
                for(i=0;i<strlen(s);i++)
                {
                        if(s[i]=='g'||s[i]=='G') g++;
                        else if(s[i]=='p'||s[i]=='P') p++;
                        else if(s[i]=='l'||s[i]=='L') l++;
                        else if(s[i]=='t'||s[i]=='T') t++;
                }
                while(g||p||l||t)
                {
                        if(g) {cout<<"G";g--}
                        if(p) {cout<<"P";p--}
                        if(l) {cout<<"L";l--}
                        if(t) {cout<<"T";t--}
                }
                cout<<endl;
                memset(s,0,sizeof(s));
        }
        return 0;
}
