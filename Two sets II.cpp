#include<iostream>
#include<vector>
#include<cstring>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
 
using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
ll dp[501][70000];
ll fun(int i,int n,int rem){
	
	if(rem==0)
		return 1;
	if(rem<0 || i>n)
		return 0;
	if(dp[i][rem]!=-1)
		return dp[i][rem];
	ll ans = fun(i+1,n,rem-i)+fun(i+1,n,rem);
	return dp[i][rem] = ans%mod;
 
}
int main(){
	int n;
	cin>>n;
	ll tmp = (n*(n+1))/2;
	if(tmp%2!=0)
		cout<<0;
	else{
		memset(dp,-1,sizeof(dp));
		cout<<(fun(1,n,tmp/2)*1LL*500000004)%mod;
	}
	// ans is dp[n][tmp/2]/2 so 500000004 is modular inverse of 2 in mod 1e9+7
	return 0;
}
