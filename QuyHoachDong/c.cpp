#include <iostream>
#include <cmath>
using namespace std;
int n, k;

int soLuong(int n, int k){
	int L[1000]={0};
	L[0]=1;
	for(int i=1; i<=n;i++){
		if(i<k){
			L[i]= pow(2,i);
		}else{
			L[i]+=L[i-1];
			for(int j=i-2; i-k>=0 && j>=i-k;j--)
				L[i]+=L[j];
		}
	}
	return L[n];
}
main(){
	cin>>n>>k;
	cout<<soLuong(n,k);
}
