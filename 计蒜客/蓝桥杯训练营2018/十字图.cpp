#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char Map[305][305];
	int n;
	cin>>n;
	int len = 4+2*(n-1);
	memset(Map,'.',sizeof(Map));
	for(int k = 1;k <= n;k++) //deep
	{
		int row = 1+2*(k-1),left = 3+2*(k-1);
		for(int j = left;j <= len+1;j++) Map[row][j]='$';//row1
		Map[row+1][left] = '$';//row2
		Map[row+2][left-2] = Map[row+2][left-1] = Map[row+2][left] = '$';//row3
		for(int i = row+3;i <= len+1;i++) Map[i][left-2] = '$';//left
	}
	Map[len-1][len+1] = Map[len][len+1] = Map[len+1][len+1] = Map[len+1][len] = Map[len+1][len-1] = '$';//center
	
	for(int i = 1;i <= len+1 ;i++)
	{
		for(int j = 1;j<=len+1;j++) printf("%c",Map[i][j]);
		for(int j = len;j >=1 ;j--) printf("%c",Map[i][j]);
		printf("\n");
	}
	for(int i = len;i >= 1 ;i--)
	{
		for(int j = 1;j<=len+1;j++) printf("%c",Map[i][j]);
		for(int j = len;j >=1 ;j--) printf("%c",Map[i][j]);
		printf("\n");
	}
	
	
	
	return 0;
}
