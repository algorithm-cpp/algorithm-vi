#include <iostream>
using namespace std;
string xauConChungDaiNhat(string s1, string s2){
	int vet[100][100]={0,0};
	s1=" "+s1;
	s2=" "+s2;
	for(int i=1; i<s1.size(); i++){
		for(int j=1; j<s2.size(); j++){
			if(s1[i]== s2[j]){
				vet[i][j]=vet[i-1][j-1]+1;
			}else{
				vet[i][j]= max(vet[i-1][j], vet[i][j-1]);
			}
		}
	}
	
	//truy vet
	string res="";
	int n=s1.size()-1,m= s2.size()-1;
	while(n>0 && m>0){
		if(s1[n]==s2[m]){
			res=s1[n] +res;
			n--;
			m--;
		}else{
			if(vet[n][m]==vet[n-1][m]) n--;
			else m--;
		}
	}
	return res;
}
main(){
	string s1, s2;
	cin>>s1>>s2;
	cout<<"Xau con dai nhat: "<<xauConChungDaiNhat(s1,s2);
}
