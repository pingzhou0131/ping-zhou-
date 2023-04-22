#include<bits/stdc++.h>
using namespace std;
int fa[10010],vis[10010],cnt,vis2[10010];
int find(int a){
	while(a!=fa[a])a=fa[a];
	return a;
}

void uni(int a,int b){
	if(find(a)>find(b))fa[find(a)]=find(b);
	else fa[find(b)]=find(a);
}
int main(){
	for(int i=0;i<10010;i++)fa[i]=i;
	int n,q;
	cin>>n;
	for(int i=0;i<n;i++){
		int n2;
		cin>>n2;
		int a;
		cin>>a;
		if(vis[a]==0){
			cnt++;
			vis[a]=1;
		}
		for(int j=0;j<n2-1;j++){
			int b;
			cin>>b;
			if(find(a)!=find(b))uni(a,b);
			if(vis[b]==0){
				cnt++;
				vis[b]=1;
			}
			a=b;
		}
	}
	int num=0;
	for(int i=1;i<=cnt;i++){
		if(vis2[find(i)]==0){
			num++;
			vis2[find(i)]=1;
		}
	}
	cout<<cnt<<' '<<num<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b))cout<<'Y'<<endl;
		else cout<<'N'<<endl;
	}
}
