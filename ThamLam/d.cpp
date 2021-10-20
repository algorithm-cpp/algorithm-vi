#include <iostream>
#include <algorithm>
using namespace std;
struct Dovat{
	int khoiLuong;
	int giaTri;
};

Dovat *list;
int n, M;
void input(){
	cin>>n;
	list=new Dovat[n];
	for(int i=0;i<n;i++){
		cin>>list[i].khoiLuong>>list[i].giaTri;
	}
	cin>>M;
}

bool dk(Dovat a, Dovat b){
	return a.giaTri >b.giaTri;
}
void slove(){
	sort(list, list+n, dk);
	int m=0, i=0, g=0;
	cout<<"Chon do vat: "<<endl;
	while( i<n &&m+list[i].khoiLuong<=M){
		m+=list[i].khoiLuong;
		g+= list[i].giaTri;
		cout<<list[i].khoiLuong<<" "<<list[i].giaTri<<endl;
		i++;
	}
	cout<<"Gia tri max: "<<g<<endl;;
}
main(){
	input();
	slove();
}
