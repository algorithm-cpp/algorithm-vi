#include <iostream>
using namespace std;
int a[100][100], n, end;

int getEnd(){
	for(int i=n-1; i>=0;i--){
		for(int j=n-1; j>=0;j--){
			if(a[i][j]==0) return i*n+j;
		}
	}
}
void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	end=getEnd();
}

void output(){
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int next(int i,int j, int x){
	for(int k=0; k<n;k++){
		if(a[i][k]==x) return 0;
		if(a[k][j]==x) return 0;
	}
	return 1;
}

void Try(int i){
	int k=i;
	//tim o trong
	while(a[k/n][k%n]!=0) k++;
	int row= k/n, col=k%n;
	for(int x=1;x<=n;x++){
		if(next(row, col, x)){
			a[row][col]=x;
			if(k==end){
				output();
			}else{
				Try(k+1);
			}
			a[row][col]=0;
		}
	}
}
main(){
	input();
	output();
	cout<<end<<endl;
	Try(0);
}
