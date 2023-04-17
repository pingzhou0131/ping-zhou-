#include<bits/stdc++.h>
using namespace std;
const int N=100010;
double a[N],b[N],s[N],y[N],efs=0.05;
int main(){
	int n1,n2;
	int maxa=0,maxb=0;
	cin>>n1;
	for(int i=0;i<n1;i++){
		int x;
		cin>>x;
		cin>>a[x];
		if(maxa<x)maxa=x;
	}
    int max=maxa;
	cin>>n2;
	for(int i=0;i<n2;i++){
		int x;
		cin>>x;
		cin>>b[x];
		if(maxb<x)maxb=x;
	}
	if(maxa<maxb){
		cout<<"0 0 0.0"<<endl;
		cout<<n1;
		for(int i=maxa;i>=0;i--){
			if(abs(a[i])>=efs)printf(" %d %.1f",i,a[i]);
		}
		cout<<endl;
	}else{
		while(maxa>=maxb){
			double num=a[maxa]/b[maxb];
			s[maxa-maxb]+=num;
			for(int i=maxb;i>=0;i--){
				if(abs(b[i])>=efs)a[i+maxa-maxb]-=b[i]*num;
			}
			int i,ep=0;
			for(i=maxa;i>=0;i--){
				if(abs(a[i])>=efs){
					if(i>ep)ep=i;break;
				}
			}
			if(i==-1)break;
			maxa=ep;
		}
		int cnt1=0;
		for(int i=max;i>=0;i--){
			if(abs(s[i])>=efs)cnt1++;
		} 
		int cnt2=0;
		for(int i=max;i>=0;i--){
			if(abs(a[i])>=efs)cnt2++;
		}
		if(cnt1>0){
			cout<<cnt1;
			for(int i=max;i>=0;i--){
				if(abs(s[i])>=efs)printf(" %d %.1f",i,s[i]);
				
			}
			cout<<endl;
		}else{
		printf("0 0 0.0\n");
		} 
		if(cnt2>0){
			cout<<cnt2;
			for(int i=max;i>=0;i--){
				if(abs(a[i])>=efs)printf(" %d %.1f",i,a[i]);
				
			}
			cout<<endl;
		}else{
		printf("0 0 0.0\n");
		} 
	}
}
