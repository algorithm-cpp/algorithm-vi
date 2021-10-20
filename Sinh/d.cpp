#include <iostream>
using namespace std;
int a[100], n;
void input(){
	cin>>n;
	a[0]=1;
}
void output(int k){
	for(int i=1 ;i<=k;i++) cout<<a[i]<<" ";
	cout<<endl;
}
void lietKe(int i, int sum, int a[]){
	for(int j=a[i-1]; j<= n-sum; j++){
		a[i]=j;
		if(sum+j==n) output(i);
		else{
			if(sum+j<n) lietKe(i+1,sum+j, a);
		}
	}
}
main(){
	input();
	lietKe(1,0,a);
}
