#include<cstdio>
#include<iostream>
using namespace std;
void hmove(int n,char a,char b,char c)
{
        if(n==1) printf("%c-->%c\n",a,c);
        else
        {
                hmove(n-1,a,c,b);
                printf("%c-->%c\n",a,c);
                hmove(n-1,b,a,c);
        }
}
int main()
{
        int n;
        while(cin>>n)
        {
                hmove(n,'A','B','C');
                cout<<endl;
        }
        return 0;
}
