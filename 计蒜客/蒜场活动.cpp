#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	for(int a=0;a<2;a++)
	{
		for(int b=0;b<2;b++)
		{
			for(int c=0;c<2;c++)
			{
				for(int d=0;d<2;d++)
				{
					for(int e=0;e<2;e++)
					{
						if(!a&&(b+c+d+e)==3) continue;
						if(!b&&(a+c+d+e)==4) continue;
						if(!c&&(a+b+d+e)==1) continue;
						if(!d&&(a+b+c+e)==4) continue;
						if(a&&(b+c+d+e)!=3) continue;
						if(b&&(a+c+d+e)!=4) continue;
						if(c&&(a+b+d+e)!=1) continue;
						if(d&&(a+b+c+e)!=4) continue;
						printf("%d %d %d %d %d\n",a,b,c,d,e);
					}
				}
			}
		}
	}
	return 0;
}
