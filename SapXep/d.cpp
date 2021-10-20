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

void quickSort(int *a,int left,int right)
{
	int l=left, r=right, temp=a[(left+right)/2];
	while(l<=r)
	{
		while(a[l]<temp && l< right) l++;
		while(a[r]> temp && r> left) r--;
		if(l<=r)
		{
			swap(a[l++],a[r--]);
		}
	}
	if(left < r) quickSort(a, left, r);
	if(l < right) quickSort(a , l, right);
}




main(){
	input();
	quickSort(a,0,n-1);
	output();
}
