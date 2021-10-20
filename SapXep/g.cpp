#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int *a, n;
void input(){
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void output(){
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
int getLength(int n){
	int count=0;
	while(n>0){
		count++;
		n/=10;
	}
	return count;
}
void radixSort(int *a, int n){
	int m=0, h=1;
	for(int i=0; i< n;i++){
		m=max(m, getLength(a[i]));
	}
	for(int i=m; i>0 ;i--){
		vector<int> b[10];
		for(int j=0; j<n;j++){
			int d= (a[j]/h)%(10);
			b[d].push_back(a[j]);
		}
		int len=0;
		for(int j=0; j<10; j++){
			for(int k=0; k< b[j].size();k++){
				a[len++]= b[j][k];
			}
		}
		h*=10;
	}
}
main(){
	input();
	radixSort(a,n);
	output();
}
