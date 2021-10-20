#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct Node{
	int data;
	Node *next=NULL;
};

class List{
	private:
		Node *root=NULL;
		Node *end=NULL;
		int length=0;
	public:
		Node *makeNode(int data){
			Node *temp=new Node;
			temp->data =data;
			return temp;
		}
		int *toArray(){
			if(root==NULL) return NULL;
			int *a=new int[length];
			Node *start=root;
			int i=0;
			while(start!=NULL){
				a[i++]=start->data;
				start=start->next;
			}
			return a;
		}
		void Sort(){
			if(root==NULL) return;
			int *a=new int[length];
			a=toArray();
			int i=0;
			sort(a,a+length);
			Node *start=root;
			while(start!=NULL){
				start->data=a[i++];
				start=start->next;
			}
		}
		
		void addFirst(int data){
			Node *temp=makeNode(data);
			if(root==NULL){
				root=temp;
				end=temp;
				length++;
				return;
			}
			temp->next=root;
			root=temp;
			length++;
			Sort();
		}
		
		void remove(int pos){
			if(pos < 0 || pos >= length){
				cout<<"Can't remove"<<endl;
				return;
			}
			int i=0;
			Node *start=root, *front;
			while(i<pos){
				front=start;
				start=start->next;
				i++;
			}
			if(pos==0){
				root=root->next;
				length--;
				return;
			}
			if(pos==length-1){
				front->next=NULL;
				end=front;
				length--;
				return;
			}
			front->next= start->next;
			length--;
		}
		
		Node *find(int data){
			Node *start= root;
			while(start!=NULL){
				if(start->data == data){
					return start;
				}
				start=start->next;
			}
			return NULL;
		}
		
		void read(){
			if(root==NULL) cout<<"NULL"<<endl;
			Node *start=root;
			while(start!=NULL){
				cout<<start->data<<" ";
				start=start->next;
			}
		}
		
		void rev(){
			if(root==NULL) return;
			int *a=toArray();
			int i=0;
			Node *start=root;
			while(start!=NULL){
				start->data=a[length-i-1];
				i++;
				start=start->next;
			}
		}
};

List a;
void menu(){
	while(true){
		int key;
		cout<<endl<<"1. Them vao ban trai list"<<endl;
		cout<<"2. Xoa bo node "<<endl;
		cout<<"3. Tim kiem node"<<endl;
		cout<<"4. In ra danh sach"<<endl;
		cout<<"5. Dao nguoc danh sach"<<endl;
		cout<<"6. Exit";
		cout<<endl<<"Chon: ";
		cin>>key;
		switch(key){
			case 1:{
				system("cls");
				int data, pos;
				cout<<"Nhap phan tu can them"<<endl;
				cin>>data;
				a.addFirst(data);
				break;
			}
			case 2:{
				system("cls");
				int pos;
				cout<<"Nhap vi tri can xoa"<<endl;
				cin>>pos;
				a.remove(pos);
				break;
			}
			case 3:{
				system("cls");
				int data;
				cout<<"Nhap node can tim"<<endl;
				cin>>data;
				Node *temp=a.find(data);
				if(temp==NULL) cout<<"Khong co node can tim"<<endl;
				else cout<<"Node can tim co dia chi o nho: "<<temp;
				break;
			}
			case 4:{
				system("cls");
				cout<<"Danh sach"<<endl;
				a.read();
				break;
			}
			case 5:{
				system("cls");
				a.rev();
				cout<<"Dao nguoc danh sach thanh cong"<<endl;
				break;
			}
			case 6:{
				return;
			}
		}
	}
}
main(){
	menu();
}
