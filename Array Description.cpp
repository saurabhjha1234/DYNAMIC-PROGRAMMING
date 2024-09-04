
#include<iostream>
#include<cstring>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;  // dp[i][j]  no of arrays have of i+1 length having j as last element 
int main(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int dp[n][x+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=x;i++)
		if(arr[0]==i || arr[0]==0)
			dp[0][i] = 1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=x;j++){
			if(arr[i]!=j && arr[i]!=0){
				continue;
			}
			dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%mod;
			if(j+1<=x)
				dp[i][j] = (dp[i][j]+dp[i-1][j+1])%mod;

		}
	}
	int ans =  0;
	for(int i=0;i<=x;i++)
		ans = (ans + dp[n-1][i])%mod;
	cout<<ans;
	return 0;
}