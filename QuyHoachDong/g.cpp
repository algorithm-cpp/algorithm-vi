#include <iostream>
using namespace std;
int kl[100], gt[100], n, k;
void input(){
	cin>>n;
	for(int i=1; i<=n;i++){
		cin>>kl[i]>>gt[i];
	}
	cin>>k;
}

int khoiLuongMax(){
	int L[100][1000]={0};
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k; j++){
			L[i][j]= L[i-1][j];
			if(kl[i] <= j && L[i][j] < gt[i] + L[i-1][j-kl[i]])
				L[i][j]= gt[i] + L[i-1][j-kl[i]];
		}
	}
	return L[n][k];
}
main(){
	input();
	cout<<"Gia tri lon nhat ma tui chua dc la: "<<khoiLuongMax();
}
