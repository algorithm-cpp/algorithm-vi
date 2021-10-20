#include<iostream>
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

void bubbleSort(int *a,int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j-1]>a[j]) swap(a[j],a[j-1]);
		}
	}
}
main(){
	input();
	bubbleSort(a,n);
	output();
}
