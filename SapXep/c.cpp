#include<iostream>
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

void insertionSort(int *a,int n){
	for(int i=0;i<n;i++){
		int temp=a[i];
		int j=i-1;
		while(j>=0 && a[j] >temp){
			a[j+1]=a[j--];
		}
		a[j+1]=temp;
		output();
		cout << endl;
	}
}
main(){
	input();
	insertionSort(a,n);
	output();
}
