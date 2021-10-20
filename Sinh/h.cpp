#include <iostream>
using namespace std;
 
int *a, n, arr[100][100]={0,0}, start, Min=1000000, thanhpho[100];
void input(){
	cout<<"Nhap so luong thanh pho n: ";
	cin>>n;
	a=new int[n+1];
	for(int i=1;i<=n;i++) a[i]=i;
	cout<<"Nhap ma tran trong so"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1; j<=n;j++){
			cin>>arr[i][j];
			if(i!=j && arr[i][j]==0) arr[i][j]=1000000;
		}
	}
	cout<<"Nhap thanh pho di dau tien: ";
	cin>>start;
	for(int i=1;i<start;i++) a[i]=i;
	for(int i=start+1;i<=n;i++) a[i-1]=i;
}
void output() {
	int m=arr[start][a[1]] + arr[a[n-1]][a[start]];
    for(int i=1 ; i <n-1 ; i++) {
        m+=arr[a[i]][a[i+1]];
    }
    if(m < Min){
    	Min=m;
    	thanhpho[1]=start;
    	for(int i=2; i<=n;i++) thanhpho[i]=a[i-1];
	}
}
int next(){
	int i=n-2;
	while(i>=1&&  a[i] > a[i+1]) i--;
	if(i< 1) return 0;
	int j=n-1;
	while(a[j] < a[i]) j--;
	swap(a[i], a[j]);
	i++;
	j=n-1;
	while(i<j){
		swap(a[i++], a[j--]);
	}
	return 1;
}
void sinh(){
	do{
		output();
	}while(next());
}
main(){
	input();
	sinh();
	cout<<"Chi phi nho  nhat la: "<<Min<<endl;
	cout<<"Cac thanh pho di qua: ";
	for(int i=1;i<=n;i++) cout<<thanhpho[i]<<" ";
}
