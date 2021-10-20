#include <iostream>
#include <algorithm>
using namespace std;
struct Job{
	int id;
	int time;
	int prevJob;
};
Job j[100];
int n, k, cx[100]={0};
void input(){
	cin>>n>>k;
	for(int i=0; i<n;i++){
		cin>>j[i].time>>j[i].prevJob;
		j[i].id=i;
	}
}
bool dk(Job a, Job b){
	return a.time<b.time;
}
int xuli(int a[], int n){
	int Max=0, t=0;
	for(int i=0;i<n;i++){
		Max=max(Max,a[i]);
	}
	for(int i=0;i<n;i++){
		if(a[i]>0)t+=Max-a[i];
	}
	return t;
}
void timeDoneJob(){
	sort(j,j+n, dk);
	int time=0;
	int count=0;
	int  timeDelay=0;
	while(count<n){
		int tempTime[100]={0};
		for(int l=0; l<k;l++){
			for(int i=0; i<n;i++){
				if(!cx[i] && (j[i].prevJob ==-1 || cx[j[i].prevJob])){
					time+=j[i].time;
					cx[i]=j[i].id;
					count++;
					tempTime[l]=j[i].time;
					break;
				}
			}
		}
		timeDelay+=xuli(tempTime, k);
	}
	cout<<"thoi gian ngan nhat: "<<time-timeDelay;
}
main(){
	input();
	timeDoneJob();
}
