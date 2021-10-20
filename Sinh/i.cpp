#include <iostream>
using namespace std;
int cot[100], cheo1[200], cheo2[200], start, banco[100][100]={0,0}, count=0;
int *a, n ;
void input(){
	cout<<"Nhap n: ";
	cin>>n;
	a=new int[n+1];
	for(int i=1;i<=n;i++) a[i]=i;
}
void reset(int start){
	for(int i=1; i<=n;i++){
		cot[i]=0;
		for(int j=1; j<=n;j++) banco[i][j]=0;
	}
	for(int i=1;i<=3*n;i++){
		cheo1[i]=0;
		cheo2[i]=0;
	}
	banco[1][start]=1;
	cot[start]=1;
	cheo1[1+start]=1;
	cheo2[2*n+1 -start]=1;
}
void output() {
	int ok=0;
	for(int i=1;i<n;i++){
		if(cot[a[i]]==0 && cheo1[a[i] +i+1]==0 && cheo2[2*n + i+1 -a[i]]==0){
			cot[a[i]]=1;
			cheo1[a[i] +i+1]=1;
			cheo2[2*n + i+1 -a[i]]=1;
			banco[i+1][a[i]]=1;
		}else{
			ok=1;
			break;
		}
	}
	if(ok==0){
		count++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<banco[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	reset(start);
}
int next(){
	int i=n-2;
	while(i>=1&&  a[i] > a[i+1]) i--;
	if(i< 1) return 0;
	int j=n-1;
	while(a[j] < a[i]) j--;
	swap(a[i], a[j]);
	i++;
	j=n-1;
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
void init(int start){
	for(int i=1;i<start;i++) a[i]=i;
	for(int i=start+1;i<=n;i++) a[i-1]=i;
}
void xepHau(int n){
	for(int i=1;i<=n;i++){
		start=i;
		reset(start);	
		init(i);
		sinh();
	}
}
main(){
	input();
	xepHau(n);
	cout<<"so luong: "<<count;
}
