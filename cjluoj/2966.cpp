#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=10005;
int pre[N],in[N],last[N];
int tot;
void Find_Last(int p1,int p2,int q1,int q2,int root)
{
        if(p1>p2) return;
        for(root=q1; in[root]!=pre[p1]; ++root);
        Find_Last(p1+1,p1+root-q1,q1,root-1,0);
        Find_Last(p1+root+1-q1,p2,root+1,q2,0);
        last[tot++]=in[root];
}
int main()
{
        int n;
        while(scanf("%d",&n)!=EOF)
        {
                for(int i=0;i<n;i++) scanf("%d",&pre[i]);
                for(int i=0;i<n;i++) scanf("%d",&in[i]);
                int len=n-1;
                tot=0;
                Find_Last(0,len,0,len,0);
                printf("%d",last[0]);
                for(int i=1;i<n;i++) printf(" %d",last[i]);
                printf("\n");
        }
        return 0;
}
///先序第一个为总根
/*1 确定根,确定左子树，确定右子树。

2 在左子树中递归。

3 在右子树中递归。

4 打印当前根。
*/

char res[N],pre[N],in[N],last[N];
void findlast(int n,char* pre,char* in,char* res)///递归构造,输入先序遍历，中序遍历，求后序遍历
{
    if(n<=0) return ;
    int p=strchr(in,pre[0])-in;///找到根节点在中序遍历的位置
    findlast(p,pre+1,in,res);///递归构造左子树的后序遍历
    findlast(n-p-1,pre+p+1,in+p+1,res+p);///递归构造右子树的后序遍历
    res[n-1]=pre[0];///添加根节点到最后面
}
int main()
{
    while(scanf("%s%s",pre,in)==2)
    {
        int n=strlen(in);
        findlast(n,pre,in,res);
        res[n]='\0';
        printf("%s\n",res);
    } return 0;
}
