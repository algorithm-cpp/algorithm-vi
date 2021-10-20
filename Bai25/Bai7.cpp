#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;
struct Node{
	string data;
	int sl=1;
	Node *right=NULL,*left=NULL;
	Node *parent=NULL;
};
class Tree{
	public:
		Node *node=NULL;
		Node *MakeNode(string data){
			Node *temp=new Node;
			temp->data=data;
			return temp;
		}
				//chieu cao cay bang de quy
		int heightTree(Node *p){
			if(p==NULL) return 0;
			return max(heightTree(p->left),heightTree(p->right))+1;
		}
		Node *getNode(Node *r){
			if(r->right==NULL && r->left==NULL) return r;
			if(r->left!=NULL) return getNode(r->left);
			if(r->right!=NULL) return getNode(r->right);
		}
		Node *find(string data){
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
		void add(string data){
			if(node==NULL){
				node= MakeNode(data);
				node->sl--;
			}
			Node *p =find(data);
			if(p!=NULL){
				p->sl++;
			}else{
				Node *temp=getNode(node);
				temp->left=MakeNode(data);
			}
		}
		
		void removeLeft(string data){
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
		void removeRight(string data){
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
		
		//chieu cao cay bang khu de quy
		int heightTree(){
			if(node==NULL) return 0;
			int h=0;
			queue<Node*>list;
			list.push(node);
			while(!list.empty()){
				int n=list.size();
				while(n--){
					Node *temp=list.front();
					if(temp->right!=NULL){
						list.push(temp->right);
					}
					if(temp->left!=NULL){
						list.push(temp->left);
					}
					list.pop();
				}
				h++;
			}
			return h;
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
			if(node==NULL){
				cout<<"null"<<endl;
				return;
			}
			vector<Node*>daduyet;
			stack<Node*> list;
			list.push(node);
			daduyet.push_back(node);
			cout<<node->data<<" ";
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
Tree t;

main(){
	fstream fin;
	string s;
	fin.open("BAI25.INP");
	while(!fin.eof()){
		fin>>s;
		t.add(s);
	}
	t.danhSachTuVaSoLanXuatHien(t.node);
}
