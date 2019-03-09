#include<iostream>
#include<cstdio>
using namespace std;
int i;
void hanoi(int n,char a,char b,char c)
{
        if(n==1) printf("%d,move %d from %c to %c\n",i++,1,a,c);
        else
        {
                hanoi(n-1,a,c,b);
                printf("%d,move %d from %c to %c\n",i++,n,a,c);
                hanoi(n-1,b,a,c);
        }

}
int main()
{
        int n;
        while(cin>>n)
        {
                i=1;
                hanoi(n,'a','b','c');
        }
}
