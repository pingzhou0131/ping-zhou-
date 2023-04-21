#include<bits/stdc++.h>
using namespace std;
struct node{
	int syg,next;
	int data;
}node[100010];
int main(){
	int n;
	int first,last,syg=-1;
	cin>>first>>n;
	for(int i=0;i<n;i++){
		int id,data,next;
		cin>>id>>data>>next;
		node[id].next=next;
		node[id].data=data;
		syg=id;
		if(next==-1)last=id;
	}
	for(int i=first;i!=-1;i=node[i].next){
		if(syg!=-1)node[i].syg=syg;
		syg=i;
	}
	for(int i=first,j=last;node[i].syg!=node[j].next&&j!=node[i].syg;i=node[i].next,j=node[j].syg){
		if(i!=j)printf("%05d %d %05d\n",j,node[j].data,i);
		printf("%05d %d ",i,node[i].data);
		if(i==j||node[i].next==j){
			cout<<-1<<endl;
		}else{
			printf("%05d\n",node[j].syg);
		}
	}
}
