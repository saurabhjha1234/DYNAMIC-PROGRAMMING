#include<iostream>
#include<set>
#include<algorithm>

#define INT_MIN -2147483648
#define INT_MAX 2147483647
 
using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 

int main(){
	int n,x;
	cin>>n>>x;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	pair<int,int> dp[1<<n];
	dp[0] = {0,x};
	for(int mask=1;mask<(1<<n);mask++){
		dp[mask] = {21,0};
		for(int i=0;i<n;i++){
			if((1<<i)&mask){
				auto tmp = dp[(1<<i)^mask];
				if(tmp.second+arr[i]<=x){
					tmp.second += arr[i];
				}
				else{
					tmp.first++;
					tmp.second = arr[i];
				}
				dp[mask]  = min(dp[mask],tmp);
			}
		}
	}
	cout<<dp[(1<<n)-1].first;
	return 0;
}
