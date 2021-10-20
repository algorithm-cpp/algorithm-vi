#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
	int data;
	Node *left=NULL;
	Node *right=NULL;
	Node *p=NULL;
};

class BinaryTree{
	public:
		Node *root=NULL;
		Node *makeNode(int data){
			Node *temp=new Node;
			temp->data=data;
			return temp;
		}
		//tim kien node co du lieu la data
		Node *find(int data){
			Node *p=root;
			while(p!=NULL){
				if(p->data==data){
					return p;
				}
				if(data < p->data){
					p=p->left;
				}else{
					p=p->right;
				}
			}
			return NULL;
		}
		//quay trai
		void left_rotation(Node *p){
			Node *temp=p;
			p=p->right;
			temp->right=p->left;
			p->left=temp;
			if(temp->p==NULL){
				root=p;
			}else{
				if(temp->p->left==temp){
					temp->p->left=p;
				}else{
					temp->p->right=p;
				}
			}
			p->p=temp->p;
			temp->p=p;
		}
		//quay phai
		void right_rotation(Node *p){
			Node *temp=p;
			p=p->left;
			temp->left=p->right;
			p->right=temp;
			if(temp->p==NULL){
				root=p;
			}else{
				if(temp->p->left==temp){
					temp->p->left=p;	
				}else{
					temp->p->right=p;
				}
			}
			p->p=temp->p;
			temp->p=p;
		}
		//chieu cao cay
		int height(Node *p){
			if(p==NULL) return 0;
			return max(height(p->left),height(p->right))+1;
		}
		int balance(Node *p){
			return height(p->left)- height(p->right);
		}
		void add(int data){
			Node *temp=makeNode(data);
			if(root==NULL){
				root=temp;
				return ;
			}
			Node *p=root;
			while(true){
				if(p->data==data){
					cout<<"Da ton tai node "<< data<<endl;
					return;
				}
				if(data < p->data){
					if(p->left!=NULL)
						p=p->left;
					else
						break;
				}else{
					if(p->right!=NULL)
						p=p->right;
					else
						break;
				}
			}
			if(data < p->data){
				p->left=temp;
				temp->p=p;
			}else{
				p->right=temp;
				temp->p=p;
			}
			//can bang cay
			while(temp!=NULL){
				int balance= height(temp->left)- height(temp->right);
				if(balance>1){
					if(data < temp->left->data){
						right_rotation(temp);
					}else{
						left_rotation(temp->left);
						right_rotation(temp);
					}
					return;
				}
				if(balance <-1 ){
					if(data > temp->right->data){
							left_rotation(temp);
					}else{
						right_rotation(temp->right);
						left_rotation(temp);
					}
					return;
				}
				temp=temp->p;
			}		
		}
		
};

BinaryTree tree;
int n;
void input(){
	cout<<"nhap so phan tu: ";
	cin>>n;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		tree.add(data);
	}
}
main(){

	int data;
	input();
	cout<<"Nhap so can tim: ";
	cin>>data;
	Node *p=tree.find(data);
	if(p==NULL){
		cout<<"Khong co so"<<endl;
	}else{
		cout<<"So can tim nam tai node co o nho: "<<p;
	}
}
