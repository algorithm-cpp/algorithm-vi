#include <iostream>
using namespace std;
int banco[100][100]={0,0}, n;
int a[]={-1, -1, 1, 1, -2, -2, 2, 2};
int b[]={ 2, -2, 2, -2, 1, -1, 1, -1};
void output(){
	for(int i=1; i<=n;i++){
		for(int j=1; j<=n;j++){
			cout<<banco[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void maDiTuan(int i, int x, int y){
	for(int j=0;j<8;j++){
		int x1=x+a[j];
		int y1= y+ b[j];
		if(x1>0 && x1 <=n && y1>0 && y1<=n && banco[x1][y1]==0){
			banco[x1][y1]=i;
			if(i < n*n) maDiTuan(i+1,x1,y1);
			else output();
			banco[x1][y1]=0;
		}
	}
}
main(){
	int x,y;
	cin>>n;
	cin>>x>>y;
	banco[x][y]=1;
	maDiTuan(2,x,y);
}
