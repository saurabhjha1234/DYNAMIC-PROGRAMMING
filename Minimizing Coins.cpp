
#include<iostream>
#include<vector>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
	int n,x;
	cin>>n>>x;
	int coins[n];
	for(int i=0;i<n;i++)
		cin>>coins[i];
	vector<ll> dp(x+1,0);
	dp[0]=0;
	for(int i=1;i<=x;i++){
		dp[i] = INT_MAX;
		for(int j=0;j<n;j++){
			if(i-coins[j]>=0)
				dp[i] = min(dp[i],1LL+dp[i-coins[j]]);
		}
	}
	if(dp[x]==INT_MAX)
		dp[x]=-1;
	cout<<dp[x];
 	return 0;

}