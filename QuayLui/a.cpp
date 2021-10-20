#include <iostream>
using namespace std;
int a[100]={0}, n;

void output(){
	for(int i=0;i<n;i++) cout<<a[i];
	cout<<endl;
}
void nhiPhan(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i==n-1){
			output();
		}else{
			nhiPhan(i+1);
		}
	}
}
main(){
	cin>>n;
	nhiPhan(0);
}
