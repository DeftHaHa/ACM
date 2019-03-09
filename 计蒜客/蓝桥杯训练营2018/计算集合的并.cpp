#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
using namespace std;
set<int> A,B;
int main()
{
	int n,m,t;
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d",&t);
		A.insert(t);
	}
	while(m--){
		scanf("%d",&t);
		B.insert(t);
	}
	A.insert(B.begin(),B.end());
	int cnt = A.size(),tot = 0;
	for(set<int>::iterator it=A.begin();it!=A.end();it++){
		printf("%d",*it);
		if(++tot!=cnt) printf(" ");
		else printf("\n");
	}
	return 0;
}
