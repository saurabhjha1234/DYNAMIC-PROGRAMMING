
#include<iostream>
#include<string>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n = s1.size(),m = s2.size();
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)
				dp[i][j] = j;
			else if(j==0)
				dp[i][j] = i;
			else if(s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else if(s1[i-1]!=s2[j-1])
				dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
		}
	}
	cout<<dp[n][m];
	return 0;
}