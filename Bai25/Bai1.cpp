#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;
struct Node{
	string data;
	Node *next=NULL;
};

class List{
	private:
		Node *root=NULL;
		Node *end=NULL;
		int length=0;
	public:
		Node *makeNode(string data){
			Node *temp=new Node;
			temp->data =data;
			return temp;
		}
		
		void addFirst(string data){
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
		}
		
		void add(string data){
			Node *temp=makeNode(data);
			if(root==NULL){
				root=temp;
				end=temp;
				length++;
			}
			end->next=temp;
			end=temp;
			length++;
		}
		
		void addPos(string data, int pos){
			Node *temp= makeNode(data);
			if(pos< 0 || pos > length){
				cout<<"Can't add "<<data<<endl;
				return;
			}
			if(pos==0){
				addFirst(data);
				return;
			}
			if(pos==length){
				add(data);
				return;
			}
			int i=0;
			Node *start= root, *front;
			while(i< pos){
				front= start;
				start=start->next;
				i++;
			}
			front->next= temp;
			temp->next= start;
			length++;
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
		
		Node *find(string data){
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
		string *toArray(){
			if(root==NULL) return NULL;
			string *a=new string[length];
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
			string *a=new string[length];
			a=toArray();
			int i=0;
			sort(a,a+length);
			Node *start=root;
			while(start!=NULL){
				start->data=a[i++];
				start=start->next;
			}
		}
		
		void rev(){
			if(root==NULL) return;
			string *a=toArray();
			int i=0;
			Node *start=root;
			while(start!=NULL){
				start->data=a[length-i-1];
				i++;
				start=start->next;
			}
		}
		
		void danhSachTuVaSoLanXuatHien(){
			int *sl=new int[length];
			string *s=new string[length];
			int n=0;
			Node *start=root;
			while(start!=NULL){
				string temp=start->data;
				int index=-1;
				for(int i=0;i<n;i++){
					if(s[i]==temp){
						index=i;
						break;
					}
				}
				if(index==-1){
					sl[n]=1;
					s[n++]= temp;
				}else{
					sl[index]++;
				}
				start=start->next;
			}
			cout<<"danh sach tu va so lan xuat hien"<<endl;
			for(int i=0; i<n;i++){
				cout<<s[i]<<" "<<sl[i]<<endl;
			}
		}
};

List a;

main(){
	fstream fin;
	string s;
	fin.open("BAI25.INP");
	while(!fin.eof()){
		fin>>s;
		a.add(s);
	}
	a.danhSachTuVaSoLanXuatHien();
}
