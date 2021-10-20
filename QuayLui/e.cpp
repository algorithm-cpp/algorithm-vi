#include <iostream>
using namespace std;

int a[100][100], n, Min=1000000, start;
int cx[100]={0}, duongDi[100], vet[100];
void input(){
	cin>>n;
	for(int i=1; i<=n;i++){
		for(int j=1; j<=n;j++){
			cin>>a[i][j];
		}
	}
	cin>>start;
	cx[start]=1;
	duongDi[0]=start;
}

void output(int n){
	if(n< Min){
		Min=n;
		for(int i=1;i<n;i++) duongDi[i]=vet[i];
	}
}
void duLich(int i,int count, int chiphi){
	for(int j=1; j<=n;j++){
		if(cx[j]==0 && a[i][j]){
			cx[j]=1;
			vet[count]=j;
			if(count==n-1){
				output(chiphi+a[i][j]);
			}else{
				duLich(j, count+1, chiphi+a[i][j]);
			}
			cx[j]=0;
		}
	}
}
main(){
	input();
	duLich(start, 1, 0);
	cout<<"chi phi nho nhat: "<<Min;
	cout<<endl<<"duong di: ";
	for(int i=0;i<n;i++) cout<<duongDi[i]<<" ";
}
