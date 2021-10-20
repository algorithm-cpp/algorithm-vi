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

void marge(int *a, int left, int mid, int right){
	int l1= left, l2=mid+1;
	int *temp=new int[right-left+1];
	for(int i=0;i<right-left+1;i++){
		if(l1<=mid && l2 <=right){
			if(a[l1] < a[l2]){
				temp[i]= a[l1++];
			}else{
				temp[i]= a[l2++];
			}
		}else{
			if(l1<=mid) temp[i]=a[l1++];
			if(l2<=right) temp[i]=a[l2++];
		}
	}
	for(int i=left;i<= right; i++){
		a[i]= temp[i-left];
	}
}

void margeSort(int *a, int left, int right){
	if(right>left){
		int mid=(right+left)/2;
		margeSort(a,left,mid);
		margeSort(a,mid+1, right);
		marge(a, left, mid, right);
		output();
		cout << ":1: "<< endl;
	}
}

main(){
	input();
	margeSort(a,0,n-1);
	output();
}
