#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100005;
#define LC p<<1,l,mid
#define RC p<<1|1,mid+1,r
long long s[4*MAXN],lazy[4*MAXN];
bool clr[4*MAXN];
int T,n,q;
int res;
void pushdown(int p,int l,int r)  //����
{
	if(clr[p])
	{
		s[p<<1] = s[p<<1|1] = lazy[p<<1] = lazy[p<<1|1] = 0;
		clr[p<<1] = clr[p<<1|1] = true;
		clr[p] = false;
	}
	if(lazy[p])
	{
		int mid=(r+l)>>1;
		s[p<<1]+=lazy[p]*(mid-l+1); //lazy[p]�洢�������Һ��Ӵ��޸ĵ�ֵ
		s[p<<1|1]+=lazy[p]*(r-mid);

		lazy[p<<1]+=lazy[p];     //*���Ʊ��
		lazy[p<<1|1]+=lazy[p];
		lazy[p]=0;
	}
}

void modify(int p,int l,int r,int x,int y,long long num)  //�����޸�
{
	if(x<=l&&r<=y)
	{
		s[p]+=(r-l+1)*num;    //*r-l��ϸ
		lazy[p]+=num;  //������
		return;
	}
	pushdown(p,l,r);//��������ֵ
	int mid=(l+r)>>1;
	if(x<=mid) modify(LC,x,y,num);
	if(y>mid) modify(RC,x,y,num);
	s[p]=s[p<<1]+s[p<<1|1];    //**���Ƹ���
}
int query2(int p,int l,int r,long long x){ 
    if(l==r){ 
        s[p]-=x; 
        return l; 
    } 
    pushdown(p,l,r); 
    int tag,mid = (l+r)/2; 
    if(s[p<<1]>=x) tag=query2(LC,x); 
    else {
        tag=query2(RC,x-s[p<<1]);
        clr[p<<1]=true;
        s[p<<1]=lazy[p<<1]=0;
    }
    s[p]=s[p<<1]+s[p<<1|1]; 
    return tag;
}
int main()
{
//	freopen("j.in","r",stdin);
//	freopen("j.out","w",stdout);
	cin>>T;
	int o,l,r,x,k;
	while(T--)
	{
		cin>>n>>q;
		memset(s,0,sizeof(s));
		memset(lazy,0,sizeof(lazy));
		memset(clr,false,sizeof(clr));
		while(q--)
		{
		cout<<"==="<<s[1]<<endl;
			scanf("%d",&o);
			if(o==1)
			{
				scanf("%d%d%d",&l,&r,&x);
				modify(1,1,n,l,r,x);
			}
			else
			{
				scanf("%d",&k); //cout<<"SUM:"<<s[1]<<endl;
			//	for(int i = 1;i<=n;i++) cout<<query(1,1,n,i,i)<<' ';
			//	cout<<endl;
				if(s[1]<k) cout<<"Trote_w is sb"<<endl;
				else
				{
					res = k;
					cout<<query2(1,1,n,k)<<endl;
				}
			}
			 ;
		}
	}
	return 0;
}
