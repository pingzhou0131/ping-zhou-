#include<bits/stdc++.h>
using namespace std;
struct {
	int id;
	int fa;
	int ma;
	int num;
	float area;
}member[1010];
struct node{
	int id;
	int people;
	double num;
	double area;
	bool a=false;
}family[10000];
int pa[10000];
bool book[10000];

int find(int a){
	if(a!=pa[a])a=find(pa[a]);
	return a;
}

void un(int a,int b){
	if(find(a)>find(b)){
		pa[find(a)]=find(b);
	}else if(find(a)<find(b)){
		pa[find(b)]=find(a);
	}
}

bool cmp(node a,node b){
	if(a.area!=b.area)return a.area>b.area;
	else return a.id<b.id;
}

int main(){
	for(int i=0;i<10000;i++){
		pa[i]=i;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>member[i].id>>member[i].fa>>member[i].ma;
		book[member[i].id]=true;
		if(member[i].fa!=-1){book[member[i].fa]=true;
		un(member[i].id,member[i].fa);}
		if(member[i].ma!=-1){book[member[i].ma]=true;
		un(member[i].id,member[i].ma);}
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int child;
			cin>>child;
			book[child]=true;
			un(member[i].id,child);
		}
		cin>>member[i].num;
		cin>>member[i].area;
	}
	
	for(int i=0;i<n;i++){
		int id=find(member[i].id);
		family[id].a=true;
		family[id].num+=member[i].num;
		family[id].area+=member[i].area;
	}
	int sum=0;
	for(int i=0;i<10000;i++){
		if(book[i])family[find(i)].people++;
		if(family[i].a)sum++;
		
	}
	
	for(int i=0;i<10000;i++){
		if(family[i].a){
			family[i].id=i;
			family[i].num=family[i].num/family[i].people;
			family[i].area=family[i].area/family[i].people;
		}
	}
	cout<<sum<<endl;
	sort(family,family+10000,cmp);
	for(int i=0;i<sum;i++){
		printf("%04d %d %.3f %.3f\n",family[i].id,family[i].people,family[i].num,family[i].area); 
	}
}
