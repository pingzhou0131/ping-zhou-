#include<bits/stdc++.h>
using namespace std;
const int N=100010;
vector<int>a[N];
int ddz[N];
int n;
double z,r,sum;
void dfs(int x,double y){
	if(ddz[x]){
		sum+=ddz[x]*y;
	}
	else{
		for(int i:a[x]){
			dfs(i,y*r);		
		}
	}
}
int main(){
	cin>>n>>z>>r;
	r=(100-r)/100;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x==0){
			cin>>ddz[i];
		}else{
			for(int j=0;j<x;j++){
				int y;
				cin>>y;
				a[i].push_back(y);
			}
		}
	}
	dfs(0,z);
	printf("%d\n",(int)sum);
} 
