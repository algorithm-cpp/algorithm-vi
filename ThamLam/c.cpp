#include <iostream>
#include <algorithm>
using namespace std;
struct Job{
	int deadline;
	int profit;
};
bool dk(Job a, Job b){
	return a.profit> b.profit;
}

Job *job;
int n, cx[1000]={0};
void input(){
	cin>>n;
	job=new Job[n+1];
	for(int i=0;i<n;i++){
		cin>>job[i].deadline>>job[i].profit;
	}	
}

int slove(){
	int total=0;
	sort(job, job+n, dk);
	for(int i=0; i<n;i++){
		int deadline= job[i].deadline;
		while(deadline){
			if(!cx[deadline]){
				total+=job[i].profit;
				cx[deadline]=1;
				break;
			}else{
				deadline--;
			}
		}
	}
	return total;
}
main(){
	input();
	cout<<slove()<<endl;
}
