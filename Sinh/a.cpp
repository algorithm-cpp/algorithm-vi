#include <iostream>
using namespace std;
int *a, n;
void input(){
	cout<<"Nhap gia tri n: ";
	cin>>n;
	a=new int[n+1];
	for(int i=0;i<n;i++) a[i]=0;
}
void output(){
	for(int i=0;i<n;i++) cout<<a[i];
	cout<<endl;
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
