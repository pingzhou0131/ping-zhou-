#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>mp;
queue<int> q;
set<int> s;
int max1=0;
void dfs(int a,int n){
	if(n>max1){
		max1=n;
		s.clear();
		s.insert(a);
	}else if(n==max1){
		s.insert(a);
	}
	for(int i:mp[a]){
		dfs(i,n+1);
	}
}
int main(){
	int n;
	int old;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a!=-1)mp[a].push_back(i);
		else old=i; 
	}
	dfs(old,1);
	cout<<max1<<endl;
	auto i=s.begin();
	cout<<*i;
	for(i++;i!=s.end();i++){
		cout<<' '<<*i;
	}
}
