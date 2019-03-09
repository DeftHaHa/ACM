#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
        map<string,int> zod;
        zod["rat"]=1;
        zod["ox"]=2;
        zod["tiger"]=3;
        zod["rabbit"]=4;
        zod["dragon"]=5;
        zod["snake"]=6;
        zod["horse"]=7;
        zod["sheep"]=8;
        zod["monkey"]=9;
        zod["rooster"]=10;
        zod["dog"]=11;
        zod["pig"]=12;
        int T;
        scanf("%d",&T);
        while(T--)
        {
                string s1,s2;
                cin>>s1>>s2;
                int a,b;
                a=zod[s1];
                b=zod[s2];
                int ans;
                if(b>a) ans=b-a;
                else ans=b+12-a;
                printf("%d\n",ans);

        }
        return 0;
}
