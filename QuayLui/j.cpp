#include <iostream>
using namespace std;
int a[100][100],n;
int cx[100]={0};
int duongDi[100];
int start, finish;
void input(){
	cin>>n;
	for(int i=1;i <=n;i++){
		for(int j=1; j<=n;j++){
			cin>>a[i][j];
		}
	}
	cin>>start>>finish;
	cx[start]=1;
	duongDi[0]=start;
}

void output(int n){
	for(int i=0; i<n; i++){
		cout<<duongDi[i]<<" ";
	}
	cout<<endl;
}
void meCung(int i, int count){
	for(int j=1; j<=n;j++){
		if(cx[j]==0 && a[i][j]){
			cx[j]=1;
			duongDi[count]=j;
			if(j==finish) output(count+1);
			else meCung(j, count+1);
			cx[j]=0;
		}
	}
}

main(){
	input();
	meCung(start,1);
}
