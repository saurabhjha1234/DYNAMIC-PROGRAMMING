
#include<iostream>
#include<cstring>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int dp[100001][1001];
int fun(int rem,int i,int n,int* price,int* pages){
	if(rem<0)
		return INT_MIN;
	if(i==n || rem==0)
		return 0;
	if(dp[rem][i]!=-1)
		return dp[rem][i];
	dp[rem][i] = max(fun(rem,i+1,n,price,pages),pages[i]+fun(rem-price[i],i+1,n,price,pages));
	return dp[rem][i];
}
int main(){
	int n,x;
	cin>>n>>x;
	int price[n+1],pages[1+n];
	for(int i=1;i<=n;i++)
		cin>>price[i];
	for(int i=1;i<=n;i++)
		cin>>pages[i];
	int dp[n+1][x+1];
	memset(dp,0,sizeof(dp));
	// cout<<max(0,fun(x,0,n,price,pages));
	// return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			dp[i][j] = dp[i-1][j];
			if(j-price[i]>=0)
				dp[i][j] = max(dp[i][j],dp[i-1][j-price[i]]+pages[i]);
		}
	}
	cout<<dp[n][x];
	return 0;
}