#include<iostream>
#include<cstdio>
using namespace std;
bool check1(float arr[],int x)
{
        if(arr[x]-arr[x-1]==arr[x-1]-arr[x-2]) return true;
        return false;
}
bool check2(float arr[],int x)
{
        if(arr[x]/arr[x-1]==arr[x-1]/arr[x-2]) return true;
        return false;
}
bool check3(float arr[],int x)
{
        if(arr[x]==arr[x-1]+arr[x-2]) return true;
        return false;
}
int main()
{
        float arr[6];
        int n;
        int i;
        while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4])
        {
                bool flag1,flag2,flag3;
                flag1=flag2=flag3=false;
                for(i=2;i<=4;i++)
                {
                        if(!check1(arr,i)) break;
                }
                if(i>4) flag1=true;
                for(i=2;i<=4;i++)
                {
                        if(!check2(arr,i)) break;
                }
                if(i>4) flag2=true;
                for(i=2;i<=4;i++)
                {
                        if(!check3(arr,i)) break;
                }
                if(i>4) flag3=true;
                float ans[5];
                if(flag1)
                {
                        float d=arr[1]-arr[0];
                        ans[0]=arr[4]+d;
                        for(i=1;i<5;i++) ans[i]=ans[i-1]+d;
                }
                else if(flag2)
                {
                        float q=arr[1]/arr[0];
                        ans[0]=arr[4]*q;
                        for(i=1;i<5;i++) ans[i]=ans[i-1]*q;
                }
                else if(flag3)
                {
                        ans[0]=arr[4]+arr[3];
                        ans[1]=ans[0]+arr[4];
                        for(i=2;i<5;i++) ans[i]=ans[i-1]+ans[i-2];
                }
                if(flag1||flag2||flag3)
                {
                        for(i=0;i<5;i++)
                        {
                                printf("%.0f ",ans[i]);
                        }
                }
                else cout<<"None";
                cout<<endl;
        }
        return 0;
}
