#include <iostream>
using namespace std;
int start[100], finish[100], god[100], n;
void input(){
	cin>>n;
	for(int i=1 ;i<=n;i++){
		cin>>start[i]>>finish[i]>>god[i];
	}
}

int tienThue(){
	int L[101]={0};
	for(int i=1; i<=n;i++){
		L[i]=god[i];
		for(int j=1;j<i;j++){
			if(finish[j]<= start[i] && L[i]< L[j] + god[i]){
				L[i]=L[j]+ god[i];
			}
		}
	}
	return L[n];
}
main(){
	input();
	cout<<"tien cho thue nhieu nhat: "<<tienThue();
}
