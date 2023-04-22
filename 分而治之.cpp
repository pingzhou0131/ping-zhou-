#include<bits/stdc++.h>
using namespace std;
int dead[10010];
int u[10010],v[10010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i];
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		memset(dead,0,sizeof(dead));
		int np;
		cin>>np;
		for(int z=0;z<np;z++){
			int x;
			cin>>x;
			dead[x]=1;
		}
		int flag=1;
		for(int j=0;j<m;j++){
			if(dead[u[j]]==0&&dead[v[j]]==0)flag=0;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
