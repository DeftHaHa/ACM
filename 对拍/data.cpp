#include<stdio.h>
#include<time.h>
#include<windows.h>
 
int main()
{
    srand(time(NULL));//随机种子
    int N=rand()%20+2;//生成100以内的n,m
    int K=rand()%10+1;
    printf("%d %d\n",N,K);
    for(int i=0;i<N;i++)
        printf("%d ",rand()%N+1);
    puts("");
}

