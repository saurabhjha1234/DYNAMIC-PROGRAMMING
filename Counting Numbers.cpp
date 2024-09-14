#include<iostream>
#include<cstring>

#define INT_MIN -2147483648
#define INT_MAX 2147483647
 
using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
ll dp[21][11][2][2];

ll fun(string& str,int n,int prev,bool leadingzeros,bool tight){
	if(n==0){
		return 1;
	}
	if(dp[n][prev+1][leadingzeros][tight]!=-1)
		return dp[n][prev+1][leadingzeros][tight];
	int ub = tight?(str[str.size()-n]-'0'):9;
	ll ans = 0;
	for(int i=0;i<=ub;i++){
		if(i==prev && leadingzeros==0)
			continue;
		ans  = (ans + 1LL*fun(str,n-1,i,leadingzeros&(i==0),(i==ub)&tight));
	}
	return dp[n][prev+1][leadingzeros][tight] = ans;
}
int main(){
	ll a,b;
	cin>>a>>b;
	if(b==0){
		cout<<1;
		return 0;
	}
	string str1 = to_string(a-1);
	string str2 = to_string(b);
	memset(dp,-1,sizeof(dp));
	ll ans1 = fun(str2,str2.size(),-1,1,1);
	if(a==0 ){
		cout<<ans1;
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	ll ans2 = fun(str1,str1.size(),-1,1,1);
	cout<<ans1-ans2;
	return 0;
	
}
