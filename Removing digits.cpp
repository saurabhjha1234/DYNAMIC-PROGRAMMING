
#include<iostream>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main(){
	int n;
	cin>>n;
	int dp[n];
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i] = INT_MAX-2;
		int tmp = i;
		int digits[10]={0};
		while(tmp){
			digits[tmp%10]=1;
			tmp/=10;
		}
		for(int j=1;j<10;j++)
			if(digits[j]==1 && j<=i)
				dp[i] = min(dp[i],1+dp[i-j]);
	}
	cout<<dp[n];
	return 0;

}