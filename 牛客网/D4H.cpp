#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n[]={1,2,3,4,5,6,7,8};
    do
    {
        printf("%d %d %d %d %d %d %d %d\n",n[0],n[1],n[2],n[3],n[4],n[5],n[6],n[7]);
    }while(next_permutation(n,n+8));
    return 0;
}
