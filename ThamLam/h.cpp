#include <iostream>
#include <algorithm>
using namespace std;
struct Char{
	char c;
	float tanSuat;
};
bool dk(Char a, Char b){
	return a.tanSuat<b.tanSuat;
}
Char ch[100];
int n;

void input(){
	cout<<"Nhap so luong ki tu: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ch[i].c>>ch[i].tanSuat;
	}
}

struct Node{
	Char c;
	Node *left=NULL, *right=NULL;
};
class Tree{
	public:
		Node *root;
		Node *makeNode(Char c){
			Node *temp=new Node;
			temp->c=c;
			return temp;
		}
		void addToTree(Char ch[], int n){
			int i=n-1;
			Node *left;
			Node *right;
			left=makeNode(ch[i]);
			i--;
			if(i>=0) right=makeNode(ch[i]);
			else return;
			Node *parent =new Node;
			parent->right=right;
			parent->left=left;
			parent->c.tanSuat= right->c.tanSuat+ left->c.tanSuat;
			root=parent;
			i--;
			while(i>=0){
				Node *left=makeNode(ch[i]);
				Node *right=root;
				Node *parent=new Node;
				Char temp;
				temp.c='\0';
				temp.tanSuat=right->c.tanSuat+ left->c.tanSuat;
				parent->c=temp;
				parent->left=left;
				parent->right=right;
				root=parent;
				i--;
			}
		}
		void codeHufffman(Node* r, string s){
			if(r->left==NULL && r->right==NULL){
				cout<<r->c.c<<" "<<s<<endl;
			}else{
				codeHufffman(r->left, s+"0");
				codeHufffman(r->right, s+"1");
			}
		}
};

Tree t;
main(){
	input();
	t.addToTree(ch,n);
	t.codeHufffman(t.root, "");
}
