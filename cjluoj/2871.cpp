#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
        float a,b,c;
        float flag;
        while(cin>>a>>b>>c)
        {
                if(a==0)
                {
                        if(b==0)
                        {
                                if(c==0) cout<<"identical equation"<<endl;
                                else cout<<"not a equation"<<endl;
                        }
                        else printf("%.2f\n",-c/b);
                }
                else
                {
                        flag=b*b-4*a*c;
                        if(flag>=0) printf("%.2f %.2f\n",(-b+sqrt(flag))/2/a,(-b-sqrt(flag))/2/a);
                        else printf("%.2f+%.2fi %.2f-%.2fi\n",-b/2/a,sqrt(-b*b+4*a*c)/2/a,-b/2/a,sqrt(-b*b+4*a*c)/2/a);
                }
        }
        return 0;
}
