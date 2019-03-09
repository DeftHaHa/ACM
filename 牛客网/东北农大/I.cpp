#include<cstdio>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
//二分搜索:
///当前搜索x，假设我们选择了某个物品的集合S，那么他们的单位重量的价值是   
/// ∑k(k∈S)vi / ∑k(k∈S)wi
///因此就变成了判断是否存在S满足下面的条件
//∑k(k∈S)vi / ∑k(k∈S)wi >=x
//变形: ∑k(k∈S)（vi-x*wi）>=0
///二分每个x对 vi-x*wi从小到大排序 
#define eps 1e-8  
double w[100005],v[100005];  
double y[100005];    //v-x*w  
double max_ave;  
int n,k; 
bool get(double x)  
{  
    int i;  
    double sum=0;  
    for(i=0;i<n;i++)  
    {  
        y[i]=v[i]-x*w[i];  
    }  
    sort(y,y+n);  
    for(i=0;i<k;i++)  
    {  
        sum+=y[n-i-1];  
    }  
    return sum>=0;
}  
void bin()  
{  
    double low,high,mid;  
    low=0.0;  
    high=0x3f3f3f3f;  
    for(int i=0;i<100;i++)  
    {  
        mid=(low+high)/2;  
        if(get(mid))  
        low=mid;  
        else high=mid;  
    }  
    printf("%.2lf\n",high);  
}  
int main()  
{  
    int T;
    cin>>T;
    while(T--)
    {
		scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)  scanf("%lf%lf",&w[i],&v[i]);  
        bin();
    }     
    return 0;  
}  
