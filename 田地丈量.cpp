#include<bits/stdc++.h>
using namespace std; 
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int lx,ly,rx,ry;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>lx>>ly>>rx>>ry;
		int x=min(rx,a)-max(lx,0);
		int y=min(ry,b)-max(ly,0);
		if(x>0&&y>0){
			sum+=x*y;
		}
	}
	cout<<sum;
}
