#include <iostream>
using namespace std;
int *a, *arr, n,m;
void input(){
	cout<<"Nhap gia tri n: ";
	cin>>n;
	a=new int[n+1];
	arr=new int[n+1];
	for(int i=0;i<n;i++){
		a[i]=0;
		cin>>arr[i];
	}
	cout<<"Nhap gia tri M: ";
	cin>>m;
}
void output(){
	int t=0;
	for(int i=0;i<n;i++){
		t+=a[i]*arr[i];
	}
	if(t==m){
		for(int i=0;i< n;i++){
			if(a[i])cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	
}
int nex_bit(){
	int i=n-1;
	while(i>=0 && a[i]==1){
		a[i--]=0;
	}
	if(i<0 ) return 0;
	a[i]=1;
	return 1;
}

void sinh(){
	do{
		output();
	}while(nex_bit());
}
main(){
	input();
	sinh();
}
