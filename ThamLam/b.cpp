#include <iostream>
#include <algorithm>
using namespace std;
struct CV{
	int start;
	int finish;
};
CV a[10001];
int n;
void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].start>>a[i].finish;
	}
}
bool dk(CV a, CV b){
	return a.finish< b.finish;
}

int slove(){
	sort(a, a+n, dk);
	int finish=0, i=0, res=0;
	while(i<n){
		if(a[i].start>=finish && a[i].finish>finish){
			res++;
			finish=a[i].finish;
		}
		i++;
	}
	return res;
}
main(){
	input();
	cout<<slove();
}
