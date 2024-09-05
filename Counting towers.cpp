
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
int main(){
	int dp[1000001][2];
	dp[1][0]=1,dp[1][1]=1;
	for(int i=2;i<=1000000;i++){
		dp[i][1] = (4LL*dp[i-1][1]+dp[i-1][0])%mod;
		dp[i][0] = (2LL*dp[i-1][0]+dp[i-1][1])%mod;
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<(dp[n][0]+1LL*dp[n][1])%mod<<endl;;
	}

	return 0;
}