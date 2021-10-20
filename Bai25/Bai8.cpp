#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
	string data;
	int sl=1;
	Node *left=NULL;
	Node *right=NULL;
	Node *p=NULL;
};

class BinaryTree{
	public:
		Node *root=NULL;
		Node *makeNode(string data){
			Node *temp=new Node;
			temp->data=data;
			return temp;
		}
		//tim kien node co du lieu la data
		Node *find(string data){
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
		//chieu cao cay
		int height(Node *p){
			if(p==NULL) return 0;
			return max(height(p->left),height(p->right))+1;
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
		int balance(Node *p){
			return height(p->left)- height(p->right);
		}
		void add(string data){
			Node *temp=makeNode(data);
			if(root==NULL){
				root=temp;
				return ;
			}
			Node *p=root;
			while(true){
				if(p->data==data){
					p->sl++;
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
		//xoa node
		void remove(Node *p){
			if(p==NULL){
				cout<<"Can't remove!"<<endl;
				return;
			}
			if(p->left==NULL && p->right==NULL){
				Node *parent=p->p;
				//neu node p la node ben trai node parent
				if(parent->left==p){
					parent->left=NULL;
					if(balance(parent) <-1) left_rotation(parent);
				}else{
					parent->right=NULL;
					if(balance(parent)>1) right_rotation(parent);
				}
				return;
			}
			if(p->left==NULL){
				//neu p la node con trai cua node cha cua p
				if(p->p->left==p){
					p->p->left=p->right;
					p->right->p= p->p;
				}else{
					p->p->right=p->right;
					p->right->p= p->p;
				}
				return;
			}
			if(p->right==NULL){
				if(p->p->left==p){
					p->p->left=p->left;
					p->left->p=p->p;
				}else{
					p->p->right=p->left;
					p->left->p=p->p;
				}
				return;
			}
			Node *temp=p->right, *nodeleft=p->left;
			if(temp->left==NULL){
				temp->left=nodeleft;
				if(p->p->left==p){
					p->p->left=temp;
				}else{
					p->p->right=temp;
				}
				return;
			}
			while(temp->left!=NULL){
				temp=temp->left;
			}
			p->data=temp->data;
			temp->p->left=temp->right;
			if(balance(p->right) <-1) left_rotation(p->right);
		}

		void duyetTruoc(Node *node){
			if(node!=NULL){
				cout<<node->data<<" ";
				duyetTruoc(node->left);
				duyetTruoc(node->right);
			}
		}
		void duyetGiua(Node *node){
			if(node!=NULL){
				duyetGiua(node->left);
				cout<<node->data<<" ";
				duyetGiua(node->right);
			}
		}
		void duyetSau(Node *node){
			if(node!=NULL){
				duyetSau(node->left);
				duyetSau(node->right);
				cout<<node->data<<" ";
			}
		}
		void duyetTruoc(){
			if(root==NULL){
				cout<<"null"<<endl;
				return;
			}
			vector<Node*>daduyet;
			stack<Node*> list;
			list.push(root);
			daduyet.push_back(root);
			cout<<root->data<<" ";
			while(!list.empty()){
				Node *p=list.top();
				Node *left=p->left, *right= p->right;
				int l=0,r=0;
				for(int i=0;i< daduyet.size();i++){
					if(daduyet[i]==left) l=1;
					if(daduyet[i]==right) r=1;
				}
				if(l==0 && left!=NULL){
					list.push(left);
					daduyet.push_back(left);
					cout<<left->data<<" ";
				}else{
					if(r==0&& right!=NULL){
						list.push(right);
						daduyet.push_back(right);
						cout<<right->data<<" ";
					}else{
						list.pop();
					}
				}
			}
		}
		void danhSachTuVaSoLanXuatHien(Node *r){
			if(r!=NULL){
				cout<<r->data<<" "<<r->sl<<endl;
				danhSachTuVaSoLanXuatHien(r->left);
				danhSachTuVaSoLanXuatHien(r->right);
			}
		}
};
BinaryTree t;

main(){
	fstream fin;
	string s;
	fin.open("BAI25.INP");
	while(!fin.eof()){
		fin>>s;
		t.add(s);
	}
	t.danhSachTuVaSoLanXuatHien(t.root);
}
