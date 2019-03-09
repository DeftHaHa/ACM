#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int N,K;
	cin>>N;
	int score[105],B[7];
	memset(B,0,sizeof(B));
	for(int i = 0 ;i < N;i++)
	{
		cin>>score[i];
		if(score[i]==100) B[1]++;
		else if(score[i]>=90) B[2]++;
		else if(score[i]>=80) B[3]++;
		else if(score[i]>=70) B[4]++;
		else if(score[i]>=60) B[5]++;
		else B[6]++;
	}
	sort(score,score+N);
	for(int i = N-1;i >= 0;i--) printf("%d\n",score[i]);
	printf("%d",B[1]);
	for(int i = 2;i <= 6;i++) printf(" %d",B[i]);
	printf("\n");
	return 0;
}
