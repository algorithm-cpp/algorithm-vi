#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long hashCode(string s){
	long code=0;
	for(int i=0;i <s.size(); i++){
		code+= s[i]*pow(2,i);
	}
	return code;
}
class HashTable{
	public:
		vector<string> table[101];
		int SIZE=101;
		void put(string s){
			table[hashCode(s)%SIZE].push_back(s);
		}
		int find(string s){
			long index= hashCode(s)%SIZE;
			int len= table[index].size();
			if(len==0) return 0;
			for(int i=0;i< len;i++){
				if(s==table[index][i])
					return 1;
			}
			return 0;
		}
};
int n;
HashTable map;
void input(){
	cout<<"Nhap so phan tu: ";
	cin>>n;
	string s;
	for(int i=0;i< n;i++){
		cin>>s;
		map.put(s);
	}
}
main(){
	input();
	string data;
	cout<<"Nhap tu khoa can tim: ";
	cin>>data;
	if(map.find(data))
		cout<<"Co "<<data<<" trong bang bam"<<endl;
	else 
		cout<<"Khong co "<<data<<endl;
}
