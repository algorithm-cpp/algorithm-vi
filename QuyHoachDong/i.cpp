#include <iostream>
using namespace std;
int a[100], n;
void input(){
	cin>>n;
	for(int i=1 ;i<=n;i++){
		cin>>a[i];
	}
}

int dayConTang(){
	int L[101]={0};
	L[0]=1;
	for(int i=1; i<=n;i++){
		L[i]=L[i-1];
		for(int j=1;j<i;j++){
			if(a[i]> a[j] && L[i] < L[j]+ 1){
				L[i]=L[j]+1;
			}
		}
	}
	return L[n];
}
main(){
	input();
	cout<<"chieu dai day con tang dai nhat: "<<dayConTang();
}
