#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int K,N;
	cin>>K;
	bool row[1005],pd[2005],nd[2005];
	int r;
	while(K--){
		memset(row,false,sizeof(row));
		memset(pd,false,sizeof(pd));
		memset(nd,false,sizeof(nd));
		bool ok = true;
		scanf("%d",&N);
		for(int c = 1;c <= N;c++)
		{
			scanf("%d",&r);
			if(!row[r]) row[r] = true;
			else ok = false;
			if(!nd[r+c]) nd[r+c] = true;
			else ok = false;
			if(!pd[r-c+N]) pd[r-c+N] = true;
			else ok = false;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
