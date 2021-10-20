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

void selectionSort(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		int index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]< a[index]) index=j;
		}
		swap(a[i],a[index]);
	}
}



main(){
	input();
	selectionSort(a,n);
	output();
}
