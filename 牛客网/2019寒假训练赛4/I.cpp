#include<string>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char s[100005];
int main()
{
    scanf("%s",s);
    int len = strlen(s);
    bool flag = false;
    int di=-1,dj=-1;
    for(int i = 0,j = len-1;i<j;i++,j--){
    	if(s[i]!=s[j]){
    		di = i;
    		dj = j;
    		break;
		}
	}
	if(di == -1){
		puts("Yes");
	}
	else{
		bool flag = true;
		for(int i = di,j = dj-1;i<j;i++,j--){
	    	if(s[i]!=s[j]){
	    		flag = false;
	    		break;
			}
		}
		if(!flag){
			flag =  true;
			for(int i = di+1,j = dj;i<j;i++,j--){
		    	if(s[i]!=s[j]){
		    		flag = false;
		    		break;
				}
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
    return 0;
}
