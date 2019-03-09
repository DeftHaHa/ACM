#include<iostream>
#include<cstring>
using namespace std;
int main()
{

        int i;
        int a,b,c;
        int start;
        bool aa[10005],bb[10005],cc[10005];
        memset(aa,false,sizeof(aa));
        memset(bb,false,sizeof(bb));
        memset(cc,false,sizeof(cc));
        while(cin>>a>>b>>c)
        {
                for(i=1000;i<=10000;i++)
                {
                        if((i-a)%3==0)
                        {
                                for(;i<10005;i+=3)
                                {
                                        aa[i]=true;
                                }
                                break;
                        }
                }
                for(i=1000;i<=10000;i++)
                {
                        if((i-b)%5==0)
                        {
                                for(;i<10005;i+=5)
                                {
                                        bb[i]=true;
                                }
                                break;
                        }
                }
                for(i=1000;i<=10000;i++)
                {
                        if((i-c)%7==0)
                        {
                                for(;i<10005;i+=7)
                                {
                                        cc[i]=true;
                                }
                                break;
                        }
                }
                for(i=1000;i<=10000;i++)
                {
                        if(aa[i]&&bb[i]&&cc[i])
                        {
                                cout<<i<<endl;
                                break;
                        }
                }
                if(i>10000) cout<<"no answer"<<endl;
                memset(aa,false,sizeof(aa));
                memset(bb,false,sizeof(bb));
                memset(cc,false,sizeof(cc));
        }
        return 0;
}
