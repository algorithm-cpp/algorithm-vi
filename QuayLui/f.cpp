#include <iostream>
using namespace std;
int banco[100][100], n;
int cot[100]={0}, cheo1[200]={0}, cheo2[200]={0};
void output(){
	for(int i=1 ; i <= n; i++ ){
		for(int j=1; j<= n;j++){
			cout<<banco[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void xepHau(int i){
	for(int j=1; j<=n;j++){
		if(!cot[j] && !cheo1[i+j] && !cheo2[n- i +j]){
			cot[j]=1; cheo1[i+j]=1; cheo2[n - i +j] =1;
			banco[i][j]=1;
			if(i==n){
				output();
			}else{
				xepHau(i+1);
			}
			cot[j]=0; cheo1[i+j]=0; cheo2[n - i +j] =0;
			banco[i][j]=0;
		}
	}
}
main(){
	cin>>n;
	xepHau(1);
}
