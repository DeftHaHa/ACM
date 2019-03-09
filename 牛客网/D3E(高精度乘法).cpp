#include<iostream>  
using namespace std;  
int main()  
{  
    int n,a,fac[50000],ans[50000]={1,1};  
    cin >> n;
    int len=1;
    for(int i=1; i<=n; i++)
	{  
        for (int j=1;j<=len;j++)
		{  
            ans[j] = ans[j]*i+fac[j];  
            fac[j] = 0;
            if (ans[j] >= 10)
			{  
                fac[j+1] += ans[j]/10;  
                ans[j] %= 10;  
                if (j==len) len++;  
            }  
        }  
    }  
    for (int i=len; i>0; i--) printf("%d",ans[i]);  
    cout<<endl;  
    return 0;  
} 
