#include <iostream>
using namespace std;
int grap[100][100], n, st;
int cx[100]={0};
void input(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1; j<=n;j++) cin>>grap[i][j];
	}
	cin>>st;
}

void nguoiDuLich(int start){
	int count=0, s=0, vet[100];
	vet[0]=start;
	cx[start]=1;
	while(count<n){
		int Min=1000000, next;
		
		for(int i=1; i<=n;i++){
			if(cx[i]==0 && grap[start][i]>0 && grap[start][i] < Min){
				Min= grap[start][i];
				next=i;
			}
		}
		cx[next]=1;
		start= next;
		vet[count+1]= next;
		if(s<n-1) s+=Min;
		count++;
	}
	s+=grap[start][vet[0]];
	cout<<"chi phi nho: "<<s<<endl;
	cout<<"duong di: ";
	for(int i=0; i<n;i++) cout<<vet[i]<<" ";	 	
}
main(){
	input();
	nguoiDuLich(st);
}
