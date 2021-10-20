#include <iostream>
using namespace std;
int n, arr[1001][1001]={0,0};

void phanTich(int n){
	arr[0][0]=1;
	for(int i=1;i<=n;i++) arr[0][i]=0;
	for(int i=1; i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i <=j){
				arr[i][j]= arr[i-1][j] +arr[i][j-i];
			}else{
				arr[i][j]=arr[i-1][j];
			}
		}
	}
	cout<<"so cach phan tich n thanh tong cac so nho hon hoac bang n la: "<<arr[n][n];
}
main(){
	cin>>n;
	phanTich(n);
}
