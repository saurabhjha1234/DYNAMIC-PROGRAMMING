
#include<iostream>
#include<vector>
#include<cstring>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int> st,tmp;
	int vis[100001];
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		int m = st.size();
		for(int j=0;j<m;j++){
			if(vis[st[j]+arr[i]]==0){
				st.push_back(st[j]+arr[i]);
				vis[st[j]+arr[i]]  =1;
			}
		}
			if(vis[arr[i]]==0){
				vis[arr[i]]=1;
				st.push_back(arr[i]);
			}

	}
	cout<<st.size()<<endl;
	for(int i=0;i<=100000;i++)
		if(vis[i]==1)
			cout<<i<<" ";
	return 0;
}