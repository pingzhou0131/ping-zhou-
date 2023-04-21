#include<bits/stdc++.h>
using namespace std;
int u[510*510];
int a[510*510];
int color[510];
int ifc[510];
int main(){
	int v,e,k;
	cin>>v>>e>>k;
	for(int i=0;i<e;i++){
	cin>>u[i]>>a[i];
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int flag=1,cnt=0;
		memset(ifc,0,sizeof(ifc));
		for(int j=1;j<=v;j++){
			cin>>color[j];
			if(ifc[color[j]]==0){
				cnt++;
			}
			ifc[color[j]]=1;
		}
		if(cnt!=k)flag=0;
		/*set<int> s;
		for(int j=1;j<=v;j++){
			cin>>color[j];
			s.insert(color[j]);
		}
		if(s.size()!=k)flag=0;*/ 
		if(flag==0){
			cout<<"No"<<endl;
		}else{
		for(int j=0;j<e;j++){
			if(color[u[j]]==color[a[j]])
			flag=0;
		}
	
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
}
