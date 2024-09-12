#include<iostream>
#include<vector>
#define INT_MIN -2147483648
#define INT_MAX 2147483647
 
using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
int main(){
	int n;
	cin>>n;
	vector<int> tmp;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		auto it = lower_bound(tmp.begin(),tmp.end(),x);
		if(it==tmp.end())
			tmp.push_back(x);
		else
			*it = x;
	}
	cout<<tmp.size();
	return 0;
}
