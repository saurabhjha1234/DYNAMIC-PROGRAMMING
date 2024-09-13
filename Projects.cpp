#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
 
using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
bool cmp(pair<int,pair<int,int>>& a , pair<int,pair<int,int>>& b){
	if(a.first<b.first)
		return true;
	else if(a.first==b.first){
		if(a.second.first>b.second.first)
			return true;
		else if(a.second.first==b.second.first)
			return a.second.second>b.second.second;
		else
			return false;
	}
	else
		return false;
 
}
ll dp[200001];
int main(){
	int n;
	cin>>n;
	vector<pair<int,pair<int,int>>> tmp;
	for(register int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		tmp.push_back({y,{x,z}});
	}
	tmp.push_back({0,{0,0}});
	sort(tmp.begin(),tmp.end(),cmp);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		pair<int,pair<int,int>> ch = {tmp[i].second.first,{0,0}};
		
		int lb = upper_bound(tmp.begin(),tmp.begin()+i,ch)-tmp.begin();
		dp[i] = dp[i-1];
		if(lb>0){
			--lb;
			dp[i] = max(dp[i],1LL*tmp[i].second.second+dp[lb]);
		}
	}
	cout<<dp[n];
	return 0;
}
