#include <iostream>
using namespace std;
int bienDoiXau(string s1, string s2){
	int a[100][100]={0,0};
	s1=" "+s1;
	s2=" "+s2;
	int ls1=s1.size();
	int ls2=s2.size();
	for(int i=1; i<ls1; i++){
		a[0][i]=i;
	}
	for(int i=1; i<ls2; i++){
		a[i][0]=i;
	}
	for(int i=1; i<ls2; i++){
		for(int j=1; j<ls1; j++){
			if(s2[i]==s1[j]) a[i][j]=a[i-1][j-1];
			else{
				a[i][j]=min(a[i-1][j], min(a[i][j-1], a[i-1][j-1]))+1;
			}
		}
	}
	return a[ls2-1][ls1-1];
}
main(){
	string s1, s2;
	cin>>s1>>s2;
	cout<<"So phep bien doi: "<<bienDoiXau(s1,s2);
}
