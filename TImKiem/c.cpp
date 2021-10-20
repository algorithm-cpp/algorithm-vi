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

int interpolutionSearch(int *a, int n, int data){
	int left=0, right=n-1, mid;
	while(data >= a[left] && data<= a[right]){
		if(a[right]- a[left]==0) return (left+right)/2;
		mid=left +(data-a[left]) *(right-left)/(a[right]- a[left]);
		if(a[mid]< data) left=mid+1;
		else
			if(a[mid] >data) right= mid-1;
			else return mid;
		
	}
	if(a[left]== data) return left;
	return -1;
}
main(){
	int data;
	input();
	cin>>data;
	cout<<"vi tri: "<<interpolutionSearch(a,n,data);
}
