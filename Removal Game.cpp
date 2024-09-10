
#include<iostream>
#include<vector>
#include<cstring>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
ll dp[5001][5001];
ll fun(int i,int j,int* arr){
	if(i==j)
		return arr[i];
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll ans1 ,ans2;
	ans1 = arr[i]+min(fun(i+2,j,arr),fun(i+1,j-1,arr));
	ans2 = arr[j]+min(fun(i+1,j-1,arr),fun(i,j-2,arr));
	return dp[i][j] = max(ans1,ans2);

}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	memset(dp,-1LL,sizeof(dp));
	ll ans = fun(0,n-1,arr);
	cout<<ans;
	return 0;
}