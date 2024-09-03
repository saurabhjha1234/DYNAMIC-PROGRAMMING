
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main(){
	int n;
	cin>>n;
	string mat[n];
	for(int i=0;i<n;i++)
		cin>>mat[i];
	if(mat[0][0]=='*' || mat[n-1][n-1]=='*'){
		cout<<0;
		return 0;
	}
	int dp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]=='*'){
				dp[i][j]=0;
			}
			else if(i==0 && j==0)
				dp[i][j]=1;
			else{
			int up=0,left=0;
			if(i>=1)
				up = dp[i-1][j];
			if(j>=1)
				left= dp[i][j-1];
			dp[i][j] = (up*1LL+1LL*left)%mod;
		}

		}
	}
	cout<<dp[n-1][n-1];
	return 0;

}