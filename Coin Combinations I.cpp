
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
	dp[0]=1;
	for(int i=1;i<=x;i++){
		ll tmp = 0;
		for(int j=0;j<n;j++){
			if(i-coins[j]>=0)
				tmp += dp[i-coins[j]];
				tmp %=mod;
		}
		dp[i] = tmp;
	}
	cout<<dp[x];
 	return 0;

}