
#include<iostream>
#include<cstring>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main(){
	int n,x;
	cin>>n>>x;
	int dp[x+1],coins[n];
	for(int i=0;i<n;i++)
		cin>>coins[i];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=x;j++){
			if(j-coins[i]>=0){
				dp[j] += dp[j-coins[i]];
				dp[j] %= mod;
			}
		}
	}
	cout<<dp[x];

	return 0;
}