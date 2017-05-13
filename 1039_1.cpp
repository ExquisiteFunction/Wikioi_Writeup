#include <iostream>
using namespace std;

int n,k;
long a[203][7];

int main(){
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k;j++){
			if (i<j) a[i][j]=0;
			else if (i==j) a[i][j]=1;
			else a[i][j]=a[i-1][j-1]+a[i-j][j];
		}
	}
	cout << a[n][k] << endl;
	return 0;
}
