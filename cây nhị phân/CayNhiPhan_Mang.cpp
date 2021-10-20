#include <iostream>
#include <queue>
#include <stack>
#define null 2000000000
#define MAX 100005
using namespace std;

class Tree{
	public:
		int root[MAX];
		void init(){
			for(int i=0;i<MAX;i++){
				root[i]=null;
			}
		}
		
		void addRoot(int data){
			if(root[0]==null){
				root[0]=data;
			}else{
				cout<<"da co node goc"<<endl;
			}
		}
		
		int find(int data){
			if(root[0]==null) return -1;
			queue<int> list;
			list.push(0);
			while(!list.empty()){
				int pos=list.front();
				list.pop();
				if(root[pos]== data) return pos;
				int right= 2*pos+2, left=2*pos+1;
				if(root[right]!=null) list.push(right);
				if(root[left]!=null) list.push(left);
			}
			return -1;
		}
		void addRight(int node, int data){
			int pos=find(node);
			if(pos==-1){
				cout<<"node khong ton tai"<<endl;
				return;
			}
			if(root[2*pos+2]!=null){
				cout<<"da co node ben phai cua node "<<node<<endl;
				return;
			}
			root[2*pos+2]=data;
		}
		
		void addLeft(int node , int data){
			int pos=find(node);
			if(pos==-1){
				cout<<"node khong ton tai"<<endl;
				return;
			}
			if(root[2*pos+1]!=null){
				cout<<"da co node ben trai cua node "<<node<<endl;
				return;
			}
			root[2*pos+1]=data;
		}
		void removeRight(int node){
			int pos=find(node);
			if(pos==-1){
				cout<<"Khong ton tai node "<<endl;
				return;
			}
			if(root[2*pos +2]==null){
				cout<<"Khong co node ben phai cua node "<<node<<endl;
				return;
			}
			int i=2*pos+2;
			if(root[2*i+1]==null && root[2*i+2]==null)
				root[i]=null;
			else cout<<"node phai cua node "<<node<<" khong phai node la"<<endl;
		}
		void removeLeft(int node){
			int pos=find(node);
			if(pos==-1){
				cout<<"Khong ton tai node "<<endl;
				return;
			}
			if(root[2*pos +1]==null){
				cout<<"Khong co node ben trai cua node "<<node<<endl;
				return;
			}
			int i=2*pos+1;
			if(root[2*i+1]==null && root[2*i+2]==null)
				root[i]=null;
			else cout<<"node trai cua node "<<node<<" khong phai node la"<<endl;
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
Tree t;
void menu(){
	int key;
	while(true){
		cout<<endl<<"1. tao node goc cho cay"<<endl;
		cout<<"2. them node la ben trai cho node x"<<endl;
		cout<<"3. them node la ben phai cho node x"<<endl;
		cout<<"4. loai node la ben trai cho node x"<<endl;
		cout<<"5. loai node la ben phai cho node x"<<endl;
		cout<<"6. tim node x"<<endl;
		cout<<"7. duyet cay"<<endl;
		cout<<"chon: ";
		cin>>key;
		switch(key){
			case 1:{
				system("cls");
				int root;
				cout<<"Nhap node goc: ";
				cin>>root;
				t.addRoot(root);
				break;
			}
			case 2:{
				system("cls");
				int data, root;
				cout<<"Nhap node: ";
				cin>>root;
				cout<<"Nhap noi dung cua node them: ";
				cin>>data;
				t.addLeft(root,data);
				break;
			}
			case 3:{
				system("cls");
				int data, root;
				cout<<"Nhap node: ";
				cin>>root;
				cout<<"Nhap noi dung cua node them: ";
				cin>>data;
				t.addRight(root,data);
				break;
			}
			case 4:{
				system("cls");
				int root;
				cout<<"Nhap node: ";
				cin>>root;
				t.removeLeft(root);
				break;
			}
			case 5:{
				system("cls");
				int root;
				cout<<"Nhap node: ";
				cin>>root;
				t.removeRight(root);
				break;
			}
			case 6:{
				system("cls");
				int data;
				cout<<"nhap noi dung node can tim: ";
				cin>>data;
				int pos= t.find(data);
				if(pos==-1) cout<<"khong tai node"<<endl;
				else cout<<"node tai vi tri "<<pos<<" trong mang"<<endl;
				break;
			}
			case 7:{
				system("cls");
				cout<<"Cay: ";
				t.duyetTruoc();
				break;
			}
		}
	}
}
main(){
	t.init();
	menu();
}
