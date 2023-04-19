#include<bits/stdc++.h>
using namespace std;
unordered_map<string,vector<string>> sxj;
unordered_map<string,int> glnum;
unordered_map<string,string>order;
void zy(string a,string b){
	if(order[a]!=""){
		glnum[order[a]]--;
	}
	glnum[b]++;
	order[a]=b;
}

int getsum(string a){
	int sum=0;
	queue<string> q;
	q.push(a);
	while(q.size()!=0){
		string s=q.front();
		sum+=glnum[s];
		q.pop();
		for(string i:sxj[s]){
			q.push(i);
		}
	}
	return sum;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		string a,b;
		cin>>a>>b;
		if(a[0]>='A'&&a[0]<='Z'){
			sxj[b].push_back(a);
		}else{
			glnum[b]++;
			order[a]=b;
		}
	}
	char o;
	cin>>o;
	while(o!='E'){
		if(o=='T'){
			string a;
			string b;
			cin>>a>>b;
			zy(a,b);
		}else{
			string b;
			cin>>b;
			cout<<getsum(b)<<endl;
		}
		//char o1=o;
		cin>>o;
		//if(o1=='Q'&&o!='E')cout<<endl;
	}
}
