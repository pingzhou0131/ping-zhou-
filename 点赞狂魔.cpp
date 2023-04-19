#include<bits/stdc++.h>
using namespace std;
struct node{
	string name;
	int cnt,sum;
	set<int> dz;
}user[150];
bool cmp(struct node a,struct node b){
	if(a.cnt!=b.cnt)return a.cnt>b.cnt;
	return a.sum<b.sum;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>user[i].name>>user[i].sum;
		for(int j=0;j<user[i].sum;j++){
			int x;
			cin>>x;
			user[i].dz.insert(x);
		}
		user[i].cnt=user[i].dz.size();
	}
	sort(user,user+n,cmp);
	if(n<3){
		cout<<user[0].name;
		for(int i=1;i<n;i++){
			cout<<' '<<user[i].name;
		}
		for(int i=1;i<=3-n;i++){
			cout<<" -";
		}
	}else{
		cout<<user[0].name;
		for(int i=1;i<3;i++){
			cout<<' '<<user[i].name;
		}
	} 
}
