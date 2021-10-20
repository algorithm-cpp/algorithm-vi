#include <iostream>
using namespace std;

int a[100]={0}, n,k;
int cx[100]={0};
void init(){
	cin>>n;
}
void output(int k){
	for(int i=1;i<=k;i++) cout<<a[i]<<" ";
	cout<<endl;
}
void toHop(int i){
	for(int j=1; j<=n;j++){
		if(cx[j]==0){
			a[i]=j;
			cx[j]=1;
			if(i==n) output(n);
			else toHop(i+1);
			cx[j]=0;
		}
	}
}
main(){
	init();
	toHop(1);
}
