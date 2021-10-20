#include <iostream>
using namespace std;
 
int *a, n ;
void input(){
	cout<<"Nhap n: ";
	cin>>n;
	a=new int[n+1];
	for(int i=1;i<=n;i++) a[i]=i;
}
void output() {
    for(int i=1 ; i <=n ; i++) {
        cout<<a[i]<<" " ;
    }
    cout<<endl ;
}
int next(){
	int i=n-1;
	while(i>=1&&  a[i] > a[i+1]) i--;
	if(i< 1) return 0;
	int j=n;
	while(a[j] < a[i]) j--;
	swap(a[i], a[j]);
	i++;
	j=n;
	while(i<j){
		swap(a[i++], a[j--]);
	}
	return 1;
}
void sinh(){
	do{
		output();
	}while(next());
}
main(){
	input();
	sinh();
}
