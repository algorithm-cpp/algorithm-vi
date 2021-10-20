#include <iostream>
 
using namespace std;
 
int *a, k , n ;
void input(){
	cout<<"Nhap n: ";
	cin>>n;
	cout<<"Nhap k: ";
	cin>>k;
	a=new int[n+1];
	for(int i=1;i<=n;i++) a[i]=i;
}
void output() {
    for(int i=1 ; i <=k ; i++) {
        cout<<a[i]<<" " ;
    }
    cout<<endl ;
}
int next(){
	int i=k;
	while(i>0 && a[i] ==n-k +i) i--;
	if(i>0){
		a[i]++;
		for(int j=i+1;j<=k;j++){
			a[j]=a[i]+ j-i;
		}
		return 1;
	}
	return 0;
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
