#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct Char{
	char c;
	int sl=0;
};
char c[100];
Char ds[100];
int lenC=0,n, d;
void input(){
	gets(c);
	n=strlen(c);
	cin>>d;
}
bool dk(Char a, Char b){
	return a.sl>b.sl;
}
void sapXep(){
	for(int i=0; i<n;i++){
		int pos=-1;
		for(int j=0; j<lenC;j++){
			if(c[i]==ds[j].c){
				pos=j; break;
			}
		}
		if(pos==-1){
			ds[i].c=c[i];
			ds[i].sl++;
			lenC++;
		}else{
			ds[pos].sl++;
		}
	}
	sort(ds, ds+lenC, dk);
	char res[100];
	for(int i=0;i<n;i++) res[i]='\0';
	for(int i=0;i<lenC;i++){
		int k=0;
		while(k<n && res[k]!='\0') k++;
		while(k<n && ds[i].sl>0){
			res[k]= ds[i].c;
			k=k+d;
			ds[i].sl--;
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		if(res[i]=='\0'){
			for(int j=0;j<lenC;j++){
				if(ds[j].sl>0){
					res[i]=ds[j].c;
					ds[j].sl--;
					break;
				}
			}
		}
	}
	cout<<"sau khi sap xep: ";
	for(int i=0;i<n;i++) cout<<res[i];
}
main(){
	input();
	sapXep();
}
