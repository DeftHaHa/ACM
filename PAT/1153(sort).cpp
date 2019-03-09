#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct TESTEE{
	string s;
	int score;
	int site;
	string date;
}tes[10005];
bool cmp1(TESTEE a,TESTEE b){
	if(a.score != b.score) return a.score > b.score;
	return a.s < b.s;
}
struct SITE{
	int site,tot;
	int score;
}sit[1005],sit2[1005];
bool cmp2(SITE a,SITE b){
	if(a.tot != b.tot) return a.tot > b.tot;
	return a.site < b.site;
}
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i= 101;i <= 999;i++){
		sit[i].tot = sit[i].score = 0;
	}
	for(int i = 0;i < N;i++){
		cin>>tes[i].s;
		scanf("%d",&tes[i].score);
		int temp = 0;
		for(int j = 1;j < 4;j++) temp = temp*10 + (tes[i].s[j]-'0');
		tes[i].site = temp;
		tes[i].date = tes[i].s.substr(4,6);
		sit[tes[i].site].tot++;
		sit[tes[i].site].score += tes[i].score;
	}
	sort(tes,tes+N,cmp1);
	int num;
	string s;
	for(int k=1;k<=M;k++){
		cin>>num>>s;
		bool flag = false;
		printf("Case %d: %d ",k,num);
		cout<<s<<endl;
		if(num==1){
			for(int i = 0;i < N;i++){
				if(tes[i].s[0] == s[0]){
					cout<<tes[i].s<<' '<<tes[i].score<<endl;
					flag = true;
				}
			}
		}
		else if(num == 2){
			int temp = 0;
			for(int i = 0;i < 3;i++) temp = temp*10 + (s[i]-'0');
			if(sit[temp].tot){
				printf("%d %d\n",sit[temp].tot,sit[temp].score);
				flag = true;
			}
		}
		else if( num == 3){
			for(int i= 101;i <= 999;i++){
				sit2[i].site = i;
				sit2[i].tot = 0;
			}
			for(int i = 0 ;i < N;i++){
				if(tes[i].date == s) sit2[tes[i].site].tot++;
			}
			sort(sit2+101,sit2+1000,cmp2);
			for(int i = 101;i <= 999;i++){
				if(sit2[i].tot){
					printf("%d %d\n",sit2[i].site,sit2[i].tot);	
					flag = true;
				}
				else break;
			}
		}
		if(!flag) printf("NA\n");
	}
	return 0;
}
