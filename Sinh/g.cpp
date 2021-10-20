#include <iostream>
using namespace std;
int *a, *giatri, *khoiluong, n,m, g=0;
void input(){
	cout<<"Nhap so luong do vat n: ";
	cin>>n;
	a=new int[n+1];
	giatri=new int[n+1];
	khoiluong=new int[n+1];
	for(int i=0;i<n;i++){
		a[i]=0;
		cout<<"Nhap khoi luong va gia tri do vat "<<i+1<<" : ";
		cin>>khoiluong[i]>>giatri[i];
	}
	cout<<"Nhap khoi luong ma tui co the chua toi da M: ";
	cin>>m;
}
void result(){
	int t=0, gt=0,kl=0;
	for(int i=0;i<n;i++){
		gt+=giatri[i]*a[i];
		kl+=khoiluong[i]*a[i];
	}
	if(kl<=m && gt> g){
		g=gt;
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
		result();
	}while(nex_bit());
}
main(){
	input();
	sinh();
	cout<<"Gia tri toi da cua do vat lay dc la: "<<g;
}
