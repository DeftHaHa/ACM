#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pre[500005],pos[500005];//��ǰ����ʹӺ���ǰ��i c�ĳ��ִ��� 
int bestl[500005]; //�ı�a[i]��ֵΪc����iΪ�����β��������� 
int ptag[500005]; //��һ��i���ֵ�λ��
int a[500005];
int main()
{
	int n,c;
	cin>>n>>c;
	memset(bestl,0,sizeof(bestl));
	memset(ptag,0,sizeof(ptag));
	memset(pre,0,sizeof(pre));
	memset(pos,0,sizeof(pos));
	for(int i = 1;i <=n ;i++) scanf("%d",&a[i]);
	for(int i = 1;i <=n ;i++)
	{
		if(a[i]==c) pre[i] = pre[i-1]+1;
		else pre[i]=pre[i-1];
	}
	for(int i = n;i >= 1;i--)
	{
		if(a[i]==c) pos[i] = pos[i+1]+1;
		else pos[i] = pos[i+1];
	}
	for(int i = 1;i <= n;i++)
	{
		bestl[i] = pre[i-1]+1; //1~i����
		int j = ptag[a[i]];
		bestl[i] = max(bestl[i],bestl[j]+1); //j~i��
		ptag[a[i]] = i;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		ans = max(ans,bestl[i]+pos[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}

//int num[500001];
//
//int main() {
//	int n, k;
//	scanf("%d %d", &n, &k);
//
//	int mav = 0, t, cnt = 0;
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &t);
//		if (t == k) cnt++;
//		else num[t] = max(num[t], cnt) + 1;
//
//		mav = max(mav, num[t] - cnt);
//	}
//
//	printf("%d", cnt + mav);
//}
