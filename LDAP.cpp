#include<bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<int,set<int>>> ma;
unordered_map<int,set<int>> with;
int n;
set<int> cnt(string s){
	int a=s.find(':');
	int b,c;
	set<int> has;
	if(a!=-1){
		b=stoi(s.substr(0,a));
		c=stoi(s.substr(a+1,s.size()-a-1));
		has.insert(ma[b][c].begin(),ma[b][c].end());
	}else{
		a=s.find('~');
		b=stoi(s.substr(0,a));
		c=stoi(s.substr(a+1,s.size()-a-1));
		has.insert(with[b].begin(),with[b].end());
		for(auto i:ma[b][c]){
			has.erase(i);
		}
	}
	return has; 
}

set<int> get(string s){
	if(s[0]>='1'&&s[0]<='9')return cnt(s);
	set<int> ans;
	if(s[0]=='&'){
		int p=1,num=1;
		while(num!=0){
			p++;
			if(s[p]=='(')num++;
			if(s[p]==')')num--;
		}
		set<int> ans1=get(s.substr(2,p-2));
		num++;
		int p2=p+2;
		p++;
		while(num!=0){
			p++;
			if(s[p]=='(')num++;
			if(s[p]==')')num--;
		}
		set<int> ans2=get(s.substr(p2,p-p2));
		for(auto i:ans1){
			if(ans2.count(i))ans.insert(i);
		}
	}else{
		int p=1,num=1;
		while(num!=0){
			p++;
			if(s[p]=='(')num++;
			if(s[p]==')')num--;
		}
		set<int> ans1=get(s.substr(2,p-2));
		num++;
		int p2=p+2;
		p++;
		while(num!=0){
			p++;
			if(s[p]=='(')num++;
			if(s[p]==')')num--;
		}
		set<int> ans2=get(s.substr(p2,p-p2));
		ans.insert(ans1.begin(),ans1.end());
		ans.insert(ans2.begin(),ans2.end());
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int dn,num;
		scanf("%d %d",&dn,&num);
		int a,b;
		for(int j=0;j<num;j++){
			scanf("%d %d",&a,&b);
			ma[a][b].insert(dn);
			with[a].insert(dn);
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		set<int> se=get(s);
		int z=1;
		for(auto j=se.begin();j!=se.end();j++,z++){
			cout<<*j;
			if(z!=se.size())cout<<' ';
		}
		if(i!=m-1)cout<<endl;
	}
}
