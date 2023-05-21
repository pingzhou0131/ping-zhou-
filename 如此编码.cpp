#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a;
	cin>>n>>m;
	cin>>a;
	cout<<m%a;
	m/=a;
	for(int i=1;i<n;i++){
		cin>>a;
		cout<<' '<<m%a;
		m/=a;
	}
}
