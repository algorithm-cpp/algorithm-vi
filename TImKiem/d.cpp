#include <iostream>
using namespace std;
long long *a, n, Fib[100]={0};
void input(){
	cin>>n;
	a=new long long[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
void initFib(){
	Fib[1]=1;
	for(int i=2;i<100;i++){
		Fib[i]=Fib[i-1]+Fib[i-2];
	}
}
void output(){
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

int fibSearch(long long *a, int n, int data){
	int k=0;
	int pos=0, inf=0;
	while(Fib[k]< n) k++;
	while(k>0){
		pos= inf+ Fib[--k];
		if(pos >=n || a[pos] >data);
		else{
			if(data > a[pos]){
				inf=pos+1;
			}else{
				return pos;
			}
		}
	}
	return -1;
}
main(){
	int data;
	initFib();
	input();
	cout<<"Nhap so can tim: ";
	cin>>data;
	cout<<"vi tri: "<<fibSearch(a,n,data);
}
