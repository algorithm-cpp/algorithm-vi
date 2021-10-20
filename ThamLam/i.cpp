#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct Type {
    int stt ;
    int bac ;
    int mau ;
};
Type myTop[100] ;
int a[100][100], n, soMau=0;
void init(int n) {
    for(int i = 1 ; i <=n ; i++) {
        myTop[i].stt = i;
        myTop[i].bac = 0 ;
        myTop[i].mau = 0 ;
    }
}
  
void input() {
    cin>>n ;
    for(int i= 1 ; i <= n; i++)
        for(int j = 1 ; j <=n ; j++)
            cin>>a[i][j] ;
}
  
void printMatrix() {
    for(int i = 1 ; i <=n ; i++) {
        for(int j = 1 ;j <=n ; j++) {
            cout<<a[i][j] <<" " ;
        }
        cout<<endl ;
    }
}
void tinhBac() {
    for(int i =  1; i <=n ; i++) {
         for(int j= 1 ; j<=n ;j++) {
            myTop[i].bac += a[i][j] ;
        }
    }
}
void sapXep() {
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		if(myTop[i].bac > myTop[j].bac){
    			swap(myTop[i], myTop[j]);
			}
		}
	}
}

int thoaManDK(int dinh , int m) {
    for(int i = 1 ; i <=n ;i++) {
      if (a[dinh][i]==1 )
        for(int j = 1 ; j<=n ;j++ )
            if(myTop[j].stt == i)
                if(myTop[j].mau==m)
                    return 0 ;
    }
    return 1 ;
}
void printResult() {
    for(int i =1 ; i <=soMau ;i++) {
        cout<<"Mau "<<i<<" : "  ;
        for(int j = 1 ; j<= n ;j++) {
            if(myTop[j].mau==i)
                cout<<myTop[j].stt<<" " ;
        }
        cout<<endl ;
    }
}
void toMau() {
    int i =1;
    int soDinhDaTo = 0 ;
    soMau=1;
    while(soDinhDaTo<n) {
        for(int j = 1 ; j<=n ;j++) {
            if(myTop[j].mau==0  && thoaManDK(myTop[j].stt,soMau)) {
                myTop[j].mau = soMau ;
                soDinhDaTo++ ;
                break;
            }
           if(j>=n) {
                soMau++ ;
            }
        }
    }
}
  
int main()
{
    input();
    init(n) ;
    tinhBac();
    sapXep();
    toMau() ;
    cout<<"So mau : " <<soMau<<endl ;
    printResult() ;
    return 0;
}
