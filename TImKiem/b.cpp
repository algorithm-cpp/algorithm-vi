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

int binarySearch(int *a, int left, int right, int data){
	if(right<left) return -1;
	int mid=(left+right)/2;
	if(data== a[mid])
		return mid;
	if(data > a[mid])
		return binarySearch(a,mid+1, right,data);
	if(data< a[mid])
		return binarySearch(a,left,mid-1, data);
}
main(){
	int data;
	input();
	cin>>data;
	cout<<"vi tri: "<<binarySearch(a,0,n,data);
}
