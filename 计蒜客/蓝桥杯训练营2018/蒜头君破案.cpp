#include<iostream>
#include<cstring>
#include<set>
using namespace std;
struct PEO{
	int a,b,c;
};
struct cmp{
	bool operator () (PEO a,PEO b) const{
		if(a.a!=b.a) return a.a<b.a;
		if(a.b!=b.b) return a.b<b.b;
		return a.c<b.c;
	}
};
set<PEO,cmp> S;
int main()
{
	int n,m;
	int a,b,c;
	scanf("%d%d",&m,&n);
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		S.insert(PEO{a,b,c});
	}
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		if(S.count(PEO{a,b,c})) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
