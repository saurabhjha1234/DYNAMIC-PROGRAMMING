
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
int main(){
	int n,m;
	cin>>n>>m;
	int dp[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = INT_MAX;
			if(i==j)
				dp[i][j] = 0;
			
			else{
				for(int k=1;k<i;k++)
					dp[i][j] = min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
				for(int k=1;k<j;k++)
					dp[i][j] = min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}