#include <iostream>
#include <queue>
#include <stack>
#define null 2000000000
#define MAX 100005
using namespace std;

class BinaryTree{
	public:
		int root[MAX];
		void init(){
			for(int i=0;i<MAX;i++){
				root[i]=null;
			}
		}
		int height(int p){
			if(root[p]==null) return 0;
			return max(height(root[2*p+1]), height(root[2*p+2]))+1;
		}
		int find(int data){
			if(root[0]==null) return -1;
			int p=0;
			while(root[p]!=null){
				if(root[p]==data) return p;
				if(data < root[p]){
					p=2*p+1;
				}else{
					p=2*p+2;
				}
			}
			return -1;
		}
		void right_rotation(int p){
			int left= 2*p +1;
			int right= 2*p +2;
			int temp=root[p];
			root[p]=root[left];
			root[right]= temp;
			root[left]= root[2*left+1];
			root[2*left+1]=null;
		}
		void left_rotation(int p){
			int left= 2*p +1;
			int right= 2*p +2;
			int temp=root[p];
			root[p]=root[right];
			root[left]= temp;
			root[right]= root[2*right+1];
			root[2*right+1]=null;
		}
		void add(int data){
			if(root[0]==null){
				root[0]=data;
				return;
			}
			int p=0;
			while(true){
				if(root[p]==data){
					cout<<"da ton tai node"<<endl;
					return;
				}
				if(data < root[p]){
					if(root[2*p+1]!=null)
						p=2*p+1;
					else
						break;
				}
				else{
					if(root[2*p+2]!=null)
						p=2*p+2;
					else
						break;
				}
			}
			if(data < root[p]){
				root[2*p+1]=data;
			}else{
				root[2*p+2]=data;
			}
		}
		
		void remove(int data){
			
			int pos= find(data);
			if(pos==-1){
				cout<<"node khong ton tai"<<endl;
				return;
			}
			//neu la node la
			if(root[2*pos+1]==null && root[2*pos+2]==null){
				root[pos]=null;
				return;
			}
			
			if(root[2*pos+1]==null){
				int l=2*pos+2;
				while(root[2*l+1]!=null){
					l=2*l+1;
				}
				int temp=root[l];
				remove(root[l]);
				root[pos]= temp;
			}else{
				int l=2*pos+1;
				while(root[2*l+2]!=null){
					l=2*l+2;
				}
				int temp=root[l];
				remove(root[l]);
				root[pos]= temp;
			}
		}
		
		void duyetTruoc(int node){
			if(root[node]!=null){
				cout<<root[node]<<" ";
				duyetTruoc(2*node+1);
				duyetTruoc(2*node+2);
			}
		}
		void duyetGiua(int node){
			if(root[node]!=null){
				duyetTruoc(2*node+1);
				cout<<root[node];
				duyetTruoc(2*node+2);
			}
		}
		void duyetSau(int node){
			if(root[node]!=null){
				duyetTruoc(2*node+1);
				duyetTruoc(2*node+2);
				cout<<root[node];
			}
		}
		
		void duyetTruoc(){
			if(root[0]==null){
				cout<<"null"<<endl;
				return;
			}
			int chuaxet[MAX];
			for(int i=0;i<MAX; i++) chuaxet[i]=1;
			stack<int> list;
			list.push(0);
			cout<<root[0]<<" ";
			while(!list.empty()){
				int pos=list.top();
				int left=2*pos+1, right= 2*pos+2;
				if(chuaxet[left] && root[left]!=null){
					list.push(left);
					cout<<root[left]<<" ";
					chuaxet[left]=0;
				}else{
					if(chuaxet[right] && root[right]!=null){
						list.push(right);
						cout<<root[right]<<" ";
						chuaxet[right]=0;
					}else{
						list.pop();
					}
				}
			}
		}
};
BinaryTree t;
void menu(){
	int key;
	while(true){
		cout<<endl<<"1. them node"<<endl;
		cout<<"2. loai node"<<endl;
		cout<<"3. tim node"<<endl;
		cout<<"4. duyet cay"<<endl;
		cout<<"chon: ";
		cin>>key;
		switch(key){
			case 1:{
				system("cls");
				int root;
				cout<<"Nhap node: ";
				cin>>root;
				t.add(root);
				break;
			}
			case 2:{
				system("cls");
				int root;
				cout<<"Nhap node: ";
				cin>>root;
				t.remove(root);
				break;
			}
			
			case 3:{
				system("cls");
				int data;
				cout<<"nhap noi dung node can tim: ";
				cin>>data;
				int pos= t.find(data);
				if(pos==-1) cout<<"khong tai node"<<endl;
				else cout<<"node tai vi tri "<<pos<<" trong mang"<<endl;
				break;
			}
			case 4:{
				system("cls");
				cout<<"Cay: ";
				t.duyetTruoc(0);
				break;
			}
		}
	}
}
main(){
	t.init();
	menu();
}
