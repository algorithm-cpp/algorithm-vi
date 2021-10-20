#include <iostream>
using namespace std;
#define MAX 1000000
int g[100][100], n, cx[100]={0}, len[100], p[100], start, finish;
void input(){
	cin>>n;
	cin>>start>>finish;
	for(int i=1; i<=n;i++){
		for(int j=1; j<=n;j++){
			cin>>g[i][j];
			if(i!=j && g[i][j]==0) g[i][j]=MAX;
		}
		len[i]=MAX;
	}
	
}

void dijkstra(int start, int finish){
	int i;
	len[start]=0;
	while(cx[finish]==0){
		for(i=1 ; i<=n;i++){
			if(!cx[i] && len[i]< MAX)
				break;
		}
		if(i==n+1){
			cout<<"Khong co duong di"<<endl;
			return;
		}
		for(int j=1;j<=n;j++){
			if(!cx[j] && len[j] < len[i]){
				i=j;
			}
		}
		cx[i]=1;
		for(int j=1; j<=n;j++){
			if(!cx[j] && len[j] > len[i] + g[i][j]){
				len[j]= len[i]+g[i][j];
				p[j]=i;
			}
		}
	}
	if(len[finish]>0 && len[finish]<MAX){
		cout<<"Duong di nho nhat: "<< len[finish]<<endl<<"Duong di: ";
		i=finish;
		while(i!=start){
			cout<<i<<"<-";
			i=p[i];
		}
		cout<<start<<endl;
	}
}
main(){
	input();
	dijkstra(start, finish);
}
