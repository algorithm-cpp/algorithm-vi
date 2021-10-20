#include <iostream>
using namespace std;
int a[100][100], b[100][100], c[100][100], n, m, k;
void nhapMaTran(int a[][100], int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
}
void input(){
	cin>>n>>m>>k;
	nhapMaTran(a,n,m);
	nhapMaTran(b,m,k);
}

void tichMaTran(int a[][100], int b[][100], int n, int m, int k){
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			c[i][j]=0;
			for(int l=0;l<m;l++)
				c[i][j]+=a[i][l]*b[l][j];
		}
	}
}
void output(int a[][100], int n, int m){
	for(int i=0; i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
main(){
	/*
	2 3 2
	
	1 2 3
	3 2 3
	
	3 2
	3 1
	4 2
	*/
	input();
	tichMaTran(a,b,n,m,k);
	output(c,n,k);
}
