
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
	int n;
	cin>>n;
	int dp[n+1];
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++){
		ll tmp = 0;
		for(int j=1;j<=6;j++){
			if(i>=j)
				tmp += (1LL*dp[i-j]);
		}
		tmp%=mod;
		dp[i] = tmp;
	}
	cout<<dp[n];
 	return 0;

}