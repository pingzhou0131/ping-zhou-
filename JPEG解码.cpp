#include<bits/stdc++.h>
using namespace std;
int lh[8][8];
double m[8][8];
double mm[8][8];
int n;
double a(int x){
	if(x)return 1;
	else return sqrt(0.5);
}
void t0(){
	int i=0,j=0,flag=1,ifzx=1;
	for(int z=0;z<n;z++){
		cin>>m[i][j];
		if(flag&&(i==0||i==7)){
			j++;
			flag=0;
			if(i)ifzx=0;
			else ifzx=1;
		}else if(flag&&(j==0||j==7)){
			i++;
			flag=0;
			if(j)ifzx=1;
			else ifzx=0;
		}else if(ifzx){
			j--;
			i++;
			flag=1;
		}else{
			j++;
			i--;
			flag=1;
		}
	}
}

void t1(){
	t0();
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	m[i][j]*=lh[i][j];
}

void t2(){
	t1();
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){
		double sum=0;
		for(int u=0;u<8;u++)
		for(int v=0;v<8;v++)sum+=0.25*a(u)*a(v)*m[u][v]*cos(acos(-1)/8*(i+0.5)*u)*cos(acos(-1)/8*(j+0.5)*v);
		mm[i][j]=sum+128;
		if(mm[i][j]>=255)mm[i][j]=255;
		else if(mm[i][j]<=0)mm[i][j]=0;
		else mm[i][j]=round(mm[i][j]);
	}
}

int main(){
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){
		cin>>lh[i][j];
	}
	int t;
	cin>>n>>t;
	if(t==0)t0();
	else if(t==1)t1();
	else t2();
	if(t<2){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%.0lf",m[i][j]);
			if(j!=7)printf(" ");
		}
		if(i!=7)printf("\n");
	}
	}else{
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				printf("%.0lf",mm[i][j]);
				if(j!=7)printf(" ");
			}
			if(i!=7)printf("\n");
		}
	}

} 
