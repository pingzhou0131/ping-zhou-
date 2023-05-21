#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int n,m,k,t,c,max=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>t>>c;
		if(max<t)max=t;
		a[t]+=c;
	}
	while(m>=a[max]&&max>k){
		m-=a[max];
		a[max-1]+=a[max];
		max--;
	}
	cout<<max;
}
