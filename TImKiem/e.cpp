#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node{
	int data;
	Node *right=NULL,*left=NULL;
	Node *parent=NULL;
};
int ok=0;
class Tree{
	public:
		Node *node=NULL;
		Node *MakeNode(int data){
			Node *temp=new Node;
			temp->data=data;
			return temp;
		}
		void addRoot(int data){
			node=MakeNode(data);
		}
		Node *find(int data){
			queue<Node*>list;
			list.push(node);
			while(!list.empty()){
				Node *temp=list.front();
				if(temp->data==data){
					return temp;
				}
				if(temp->right!=NULL){
					list.push(temp->right);
				}
				if(temp->left!=NULL){
					list.push(temp->left);
				}
				list.pop();
			}
			return NULL;
		}
		void addRight(int Parent, int data){
			Node *temp=MakeNode(data);
			if(this->node==NULL){
				node=temp;
				return;
			}
			
			Node *parent=find(Parent);
			temp->parent=parent;
			if(parent==NULL){
				cout<<"Exception: find not found"<<endl;
			}else{
				if(parent->right!=NULL){
					cout<<"Exception: Can't insert node"<<endl;
				}else{
					parent->right=temp;
				}
			}
		}
		void addLeft(int Parent, int data){
			Node *temp=MakeNode(data);
			if(this->node==NULL){
				node=temp;
				return;
			}
			Node *parent=find(Parent);
			temp->parent=parent;
			if(parent==NULL){
				cout<<"Exception: find not found"<<endl;
			}else{
				if(parent->left!=NULL){
					cout<<"Exception: Can't insert node"<<endl;
				}else{
					parent->left=temp;
				}
			}
		}
		
		void removeLeft(int data){
			Node *temp=find(data);
			if(temp==NULL){
				cout<<"Can't remove"<<endl;
				return;
			}
			if(temp->left==NULL){
				return;
			}
			if(temp->left->right== NULL && temp->left->left ==NULL){
				temp->left=NULL;
			}else{
				cout<<"Can't remove"<<endl;
			}
		}
		void removeRight(int data){
			Node *temp=find(data);
			if(temp==NULL){
				cout<<"Can't remove"<<endl;
				return;
			}
			if(temp->right==NULL){
				return;
			}
			if(temp->right->right== NULL && temp->right->left ==NULL){
				temp->right=NULL;
			}else{
				cout<<"Can't remove"<<endl;
			}	
		}
		
		//chieu cao cay bang de quy
		int heightTree(Node *p){
			if(p==NULL) return 0;
			return max(heightTree(p->left),heightTree(p->right))+1;
		}
	
		void duyetTruoc(Node *node){
			if(node!=NULL){
				cout<<node->data<<" ";
				duyetTruoc(node->left);
				duyetTruoc(node->right);
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
				Node *pos= t.find(data);
				if(pos==NULL) cout<<"khong ton tai "<<data<<endl;
				else cout<<"node can tim co dia chi: "<<pos<<endl;
				break;
			}
			case 7:{
				system("cls");
				cout<<"Cay: ";
				t.duyetTruoc(t.node);
				break;
			}
		}
	}
}
main(){
	menu();
}
