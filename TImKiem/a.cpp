#include <iostream>
using namespace std;
int *a, n;
void input(){
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void output(){
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

int search(int *a, int n, int data){
	for(int i=0;i<n;i++){
		if(a[i]==data) return i;
	}
	return -1;
}

main(){
	int data;
	input();
	cin>>data;
	cout<<"vi tri: "<<search(a,n,data);
}
