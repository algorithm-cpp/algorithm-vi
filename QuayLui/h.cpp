#include <iostream>
#include <cmath>
#define MAX 100
using namespace std;

int a[MAX], n, sumOfArray=0, Min=1000000;
int team1[MAX/2], team2[MAX/2];
int cx[MAX]={0};

void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sumOfArray+=a[i];
	}
}

void resual(int sum){
	if(abs(sum-(sumOfArray-sum)) < Min){
		Min=abs(sum-(sumOfArray-sum));
		int k1=0, k2=0;
		cout<<endl;
		for(int i=0;i<n;i++){
			if(cx[i]==1){
				team1[k1++]= a[i];
			}else{
				team2[k2++]=a[i];
			}
		}
	}
}

void tugOfWar(int i, int sum){
	for(int j=0;j<n;j++){
		if(cx[j]==0){
			cx[j]=1;
			if(i==n/2-1){
				resual(sum+a[j]);
				if((sum+a[j])*2==sumOfArray) return;
			}else{
				tugOfWar(i+1, sum+a[j]);
			}
			cx[j]=0;
		}
	}
}
main(){
	int sum1=0, sum2=0;
	input();
	tugOfWar(0,0);
	for(int i=0;i <n/2;i++){
		cout<<team1[i]<<" ";
		sum1+=team1[i];
	}
	cout<<endl;
	for(int i=0; i<n-n/2; i++){
		cout<<team2[i]<<" ";
		sum2+= team2[i];
	}
	cout<<endl<<"tong day 1: "<<sum1<<endl;
	cout<<"tong day 2: "<<sum2<<endl;
}
