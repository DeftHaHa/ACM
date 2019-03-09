#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	string s;
	int cnt = 0;
	double sum = 0.0;
	while(N--){
		bool ok = true;
		cin>>s;
		int len = s.length();
		double num = 0;
		int pos = -1;
		bool nag = false;
		for(int i = 0;i < len;i++){
			if(i==0 && s[i]=='-'){
				nag = true;
				continue;
			}
			else if(s[i]=='.'){
				if(pos != -1) ok = false;
				pos = i;
				break;
			}
			else if(s[i]>'9'||s[i]<'0'){
				ok = false;
				break;
			}
			num = num*10.0 + (s[i]-'0');
		}
		if(pos!=-1 && len-pos-1 > 2) ok = false;
		double t = 0,tot = 1;
		if(pos!=-1 && ok){
			for(int i = pos+1;i < len;i++){
				if(s[i]>'9'||s[i]<'0'){
					ok = false;
					break;
				}
				t = t*10.0 + (s[i]-'0');
				tot *= 10;
			}
			num += t/tot;
		}
		if(ok && num >= -1000.0 && num <= 1000.0){
			cnt++;
			if(nag) num = -num;
			sum += num;
		}
		else printf("ERROR: %s is not a legal number\n",s.c_str());
	}
	if(cnt==0) printf("The average of 0 numbers is Undefined\n");
	else if(cnt==1) printf("The average of 1 number is %.2lf\n",sum/(double)cnt);
	else printf("The average of %d numbers is %.2lf\n",cnt,sum/(double)cnt);
	return 0;
}
