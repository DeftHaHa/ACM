#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int MAXJ=1<<17;
struct Sta
{
	int sta[2],step;
};
int w[17]={149,110,196,8,123,155,159,199,38,29,196,92,43,79,180,149,150};
queue<Sta> q;
void display(Sta a)
{
	for(int i=0;i<17;i++)
	{
		if(a.sta[0]>>i&1) printf("%d ",w[i]);
	} printf(" ----- ");
	for(int i=0;i<17;i++)
	{
		if(a.sta[1]>>i&1) printf("%d ",w[i]);
	}  printf("======%d",a.step);
	printf("\n");
}
void display1(int x)
{
	for(int i=0;i<17;i++)
	{
		if(!(x>>i&1)) printf("%d ",w[i]);
		else printf(" ");
	}printf("###\n");
}
void display2(int x)
{
	for(int i=0;i<17;i++)
	{
		 printf("%d",(x>>i&1));
	}printf("$$$\n");
}
int bfs()
{
	Sta st;
	st.step=0;
	st.sta[0]=MAXJ-1;
	st.sta[1]=0;
	q.push(st);
	while(!q.empty())
	{
		Sta temp=q.front();  //display(temp);
		q.pop();
		Sta Next;
		Next.step=temp.step+1;       // display1(temp.sta[0]) ;printf("==========\n");
		for(int i=temp.sta[0];i;i=(i-1)&temp.sta[0])
		{                            
			int tot=0;
			for(int j=0;j<17;j++)
			{
				if(i>>j&1) tot+=w[j];
				if(tot>200) break;
			}
			if(tot<=200)
			{                  
				Next.sta[0]=temp.sta[0]-i;
				if(!Next.sta[0]) return Next.step*12-6;
				Next.sta[1]=temp.sta[1]+i;
				for(int j=0;j<17;j++)
				{
					if(Next.sta[1]>>j&1)
					{
						Next.sta[0]+=1<<j;
						Next.sta[1]-=1<<j;
						break;
					}        
				}     //display1(Next.sta[1]); cout<<"              "<<"YES"<<endl;   
				q.push(Next);
			}
		}
	}
}
int main()
{
	cout<<bfs()<<endl;
	return 0;
}
