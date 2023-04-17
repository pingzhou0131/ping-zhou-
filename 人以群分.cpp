#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int max=0,min=0,num1=0,num2=0;
	for(int i=0,j=n-1;i<=j;i++,j--){
		if(i==j){
			max+=a[i];
			num1++;
			continue;
		}
		max+=a[i];
		num1++;
		num2++;
		min+=a[j];
	}
	cout<<"Outgoing #: "<<num1<<endl<<"Introverted #: "<<num2<<endl<<"Diff = "<<max-min<<endl;

} 
