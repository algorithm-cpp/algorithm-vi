#include <iostream>
#include <cmath>
using namespace std;
int n, k, t=0;

int soLuong(int n, int k){
	int L[1000]={0};
	L[0]=1;
	for(int i=0;i<k;i++) L[i]=0;
	L[k]=1;
	for(int i=k+1; i<=n;i++){
		L[i]+=L[i-1]+n-k;
	}
	return L[n];
}

main(){
	cin>>n>>k;
	for(int i=k;i<=n; i++){
		t+=soLuong(n,i);
	}
	cout<<t;
	
}
