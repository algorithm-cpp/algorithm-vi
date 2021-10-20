#include <iostream>
using namespace std;
int a[100]={0}, n;
int kl[100], gt[100], gtMax=0, klMax;
void input(){
	cin>>n;
	for(int i=0;i< n;i++){
		cin>>gt[i]>>kl[i];
	}
	cin>>klMax;
}
void output(int gt, int kl){
	if( kl<=klMax && gt >gtMax){
		gtMax=gt;
	}
}
void nhiPhan(int i, int giatri, int khoiluong){
	for(int j=0;j<=1;j++){
		giatri+=j *gt[i];
		khoiluong+= j* kl[i];
		if(i==n-1){
			output(giatri, khoiluong);
		}else{
			nhiPhan(i+1,giatri, khoiluong);
		}
	}
}
main(){
	input();
	nhiPhan(0,0,0);
	cout<<"Gia tri lon nhat cua do vat la: "<<gtMax;
}
