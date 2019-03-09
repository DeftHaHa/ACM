#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct STU{
	string name;
	int score[5];
	STU(){score[0] = 0;}	
}s[105];
bool cmp1(STU a , STU b){if(a.score[1]!=b.score[1])return a.score[1] > b.score[1];return a.name<b.name;}
bool cmp2(STU a , STU b){if(a.score[2]!=b.score[2])return a.score[2] > b.score[2];return a.name<b.name;}
bool cmp3(STU a , STU b){if(a.score[3]!=b.score[3])return a.score[3] > b.score[3];return a.name<b.name;}
bool cmp4(STU a , STU b){if(a.score[4]!=b.score[4])return a.score[4] > b.score[4];return a.name<b.name;}
bool cmp5(STU a , STU b){if(a.score[0]!=b.score[0])return a.score[0] > b.score[0];return a.name<b.name;}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i = 0;i < N;i++){
		cin>>s[i].name;
		scanf("%d%d%d%d",&s[i].score[1],&s[i].score[2],&s[i].score[3],&s[i].score[4]);
		s[i].score[0] = s[i].score[1] + s[i].score[2] + s[i].score[3] + s[i].score[4];
	}
	sort(s,s+N,cmp1);
	printf("%s",s[0].name.c_str());
	for(int i = 1;i < 4;i++) printf(" %s",s[i].name.c_str());
	printf("\n");
	sort(s,s+N,cmp2);
	printf("%s",s[0].name.c_str());
	for(int i = 1;i < 4;i++) printf(" %s",s[i].name.c_str());
	printf("\n");
	sort(s,s+N,cmp3);
	printf("%s",s[0].name.c_str());
	for(int i = 1;i < 4;i++) printf(" %s",s[i].name.c_str());
	printf("\n");
	sort(s,s+N,cmp4);
	printf("%s",s[0].name.c_str());
	for(int i = 1;i < 4;i++) printf(" %s",s[i].name.c_str());
	printf("\n");
	sort(s,s+N,cmp5);
	printf("%s",s[0].name.c_str());
	for(int i = 1;i < 4;i++) printf(" %s",s[i].name.c_str());
	printf("\n");
	return 0;
}
