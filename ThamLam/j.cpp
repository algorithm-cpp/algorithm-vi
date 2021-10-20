#include<iostream>
using namespace std;
#define MAX  10000 
int a[100][100], n, m, sc, w;
int chuaxet[100]={0};
int cck[100][3];
void nhap(){
	 int i, j, k;
	 cin>>n>>m;
	 cout<<"So dinh: "<<n<<endl;
	 cout<<"So canh: "<<m<<endl;
	 for (i = 1; i <= n; i++){
		chuaxet[i] = 1;
	  	for (j = 1; j <= n; j++)
	   	a[i][j] = MAX;
	 }
//nhap do thi bang danh sach canh
	 for (int p = 1; p <= m; p++){
		  cin>>i>>j>>k;
		  a[i][j] = k;
		  a[j][i] = k;
	 }
}
void PRIM(int u){
	 int k, top, min, l, t;
	 int s[100];//mang chua dinh cua cay khung nho nhat
	 sc = 0; w = 0;
	 top = 1;
	 s[top] = u;
	 chuaxet[u] = 0;
	 while (sc<n - 1) {
		  min = MAX;
		  //tim canh co do dai nho nhat voi cac dinh trong s[]
		  for (int i = 1; i <= top; i++){
			   t = s[i];
			   for (int j = 1; j <= n; j++){
				    if (chuaxet[j] && min>a[t][j]){
					     min = a[t][j];
					     k = t;
					     l = j;
				    }
			   }
		  }
		  sc++;
		  w = w + min;
		  cck[sc][1] = k;
		  cck[sc][2] = l;
		  chuaxet[l] = 0; 
		  top++;
		  s[top] = l;
	 }
}
void Result(){
	 cout<<"Do dai ngan nhat:"<< w<<endl;
	 cout<<"Cac canh cua cay khung nho nhat"<<endl;
	 for (int i = 1; i <= sc; i++)
	  	cout<< cck[i][1]<<" "<< cck[i][2]<<endl;
}
main(){
 nhap(); 
 PRIM(1);
 Result();
}
