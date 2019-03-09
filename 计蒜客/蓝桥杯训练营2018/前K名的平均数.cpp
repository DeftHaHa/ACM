#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int N,K;
	cin>>N;
	int score[105];
	for(int i = 0 ;i < N;i++) cin>>score[i];
	sort(score,score+N);
	double sum;
	cin>>K;
	for(int i = N-1;i >= N-K;i--) sum+=(double)score[i];
	printf("%.2lf\n",sum/K);
	return 0;
}
