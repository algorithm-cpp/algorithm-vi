#include <iostream>
#include <algorithm>
using namespace std;
int a[200001], n;
void input(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
}

int slove(){
	int m=0, i=0;
	sort(a, a+n);
	while(n>1){
		if(a[i] > n-1){
			break;
		}
		m=+ a[i];
		n=n-a[i]-1;
		i++;
	}
	m=m+n-1;
	return m;
}
main(){
	input();
	cout<<slove();
}
