#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	double i,yl;
	cin>>n>>i>>yl;
	for(int j=1;j<=n;j++){
		cin>>x;
		yl+=x/pow(1+i,j);
	}
	printf("%f",yl);
}
