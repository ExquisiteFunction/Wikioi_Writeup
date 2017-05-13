//1018_2

#include <iostream>
#include <cstring>

using namespace std;

#define N 25

struct str{
	string s;
	int len;
	int visit;
} ss[N];
int n;
char ch;
int con[N][N]={0};

int lenn(int l,int r){
	int len1=ss[l].len,len2=ss[r].len;
	for (int k=1;(k<len1)&&(k<len2);k++)
	{
		bool flag=1;
		for (int i=len1-k,j=0;i<len1;i++,j++)
		{
			if (ss[l].s[i]!=ss[r].s[j]){
				flag=0;break;
			}
		}
		if (flag) return con[l][r]=k;
	}
	return 0;
}

int dfs(int pos){
	int ans=0,m=0;
	for (int i=0;i<n;i++){
		if (ss[i].visit && con[pos][i]){
			ss[i].visit--;
			ans=dfs(i);
			ans+=ss[i].len-con[pos][i];
			if (ans>m) m=ans;
			ss[i].visit++;
		}
	}
	return m;
}

int main(){
	int m,ans;
	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> ss[i].s;
		ss[i].len=ss[i].s.length();
		ss[i].visit=2;
	}
	cin >> ch;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			lenn(i,j);
	m = 0;
	for (int i=0;i<n;i++){
		if (ss[i].s[0]==ch)
		{
			ss[i].visit--;
			ans=dfs(i);
			ans+=ss[i].len;
			if (ans>m) m=ans;
			ss[i].visit++;
		}
	}
	cout << m;
	return 0;
}
