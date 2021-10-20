#include <iostream>
 
using namespace std;
 
int *a, k, n, m, ok=0;
int *arr;
void input(){
	cout<<"Nhap n: ";
	cin>>n;
	a=new int[n+1];
	arr=new int[n+1];
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1; i<=n;i++) cin>>arr[i];
	cout<<"Nhap k: ";
	cin>>k;
	cout<<"Nhap m: ";
	cin>>m;
}
void output() {
	int t=0;
    for(int i=1 ; i <=k ; i++) {
    	t+=arr[a[i]];
    }
    if(t==m){
    	ok=1;
    	for(int i=1; i<=k;i++) cout<<arr[a[i]]<<" ";
    	cout<<endl ;
	}
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
    if(ok==0) cout<<"Khong co day con "<<k<<" phan tu co tong bang "<<m<<endl;
}
