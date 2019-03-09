#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
bool bei[1000005];
int num[1000005];
int main()
{
    int n,x;
    cin>>n;
    int ans=0;
    
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        num[x]++;
    }
    
    memset(bei,false,sizeof(bei));
    for(int i=0;i<1000005;i++)
    {
        if(num[i])
        {
       	 	for(int j=i*2;j<1000005;j+=i)
        	{
            	if(num[j]) 
				{
					ans+=num[i];break;
				}
        	}
        }
    }
    cout<<ans<<endl;
	return 0;
}
