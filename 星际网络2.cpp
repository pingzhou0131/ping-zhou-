#include<bits/stdc++.h>
using namespace std;
int n;
struct xd{
	string l;
	string r;
	int id;
};
vector<xd> v;
bool cmp(xd a,xd b){
	return a.l<=b.l;
}
void act1(){
		int flag=1,id;
		string l,r;
		cin>>id>>l>>r;
		for(auto i:v){
			if(l<=i.r&&r>=i.l){
				if(id!=i.id){
				flag=0;
				break;
				}else if(l>=i.l&&r<=i.r){
				flag=0;
				break;
				}
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			xd a;
			a.id=id;
			a.l=l;
			a.r=r;
			v.push_back(a);
			sort(v.begin(),v.end(),cmp);
		}else{
			cout<<"NO"<<endl;
		}
}
void act2(){
	string s;
	cin>>s;
	int id=0;
	for(auto i:v){
		if(s>=i.l&&s<=i.r){
			id=i.id;
			break;
		}
	}
	cout<<id<<endl;
}
void act3(){
	string l,r;
	int id=0;
	cin>>l>>r;
	for(auto i:v){
		if(l>=i.l&&r<=i.r){
			id=i.id;
			break;
		}
	}
	cout<<id<<endl;
}
int main(){
	int q;
	cin>>n>>q;
	for(int i=0;i<q;i++){
		int a;
		cin>>a;
		if(a==1)act1();
		else if(a==2)act2();
		else if(a==3)act3();
	}
} 
