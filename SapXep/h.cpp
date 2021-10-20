#include <iostream>

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

void shakerSort(int *a,int n){
	int left=0, right=n-1, i ,j ,k;
	while(left <right){
		for(i=left ; i < right; i++){
			if(a[i] > a[i+1]){
				swap(a[i], a[i+1]);
				k=i;
			}	
		}
		right=k;
		for(i= right; i>left; i--){
			if(a[i-1] > a[i]){
				swap(a[i], a[i-1]);
				k=i;
			}
		}
		left=k;
	}
}
main(){
	input();
	shakerSort(a,n);
	output();
}
