#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct Node{
	string data;
	Node *next=NULL;
	Node *prev=NULL;
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
		string *toArray(){
			if(root==NULL) return NULL;
			string *a=new string[length];
			Node *start=root;
			int i=0;
			while(i<length){
				a[i++]=start->data;
				start=start->next;
			}
			return a;
		}
		void Sort(){
			if(root==NULL) return;
			string *a=toArray();
			int i=0;
			sort(a,a+length);
			Node *start=root;
			while(i<length){
				start->data=a[i++];
				start=start->next;
			}
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
			root->prev=temp;
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
				root->prev= NULL;
				length--;
				return;
			}
			if(pos==length-1){
				end=front;
				end->next=NULL;
				length--;
				return;
			}
			front->next= start->next;
			start->next->prev=front;
			length--;
		}
		
		Node *find(string data){
			Node *start= root;
			int i=0;
			while(i<length){
				if(start->data == data){
					return start;
				}
				start=start->next;
				i++;
			}
			return NULL;
		}
		
		void read(){
			if(root==NULL) cout<<"NULL"<<endl;
			Node *start=root;
			int i=0;
			while(i<length){
				cout<<start->data<<" ";
				start=start->next;
				i++;
			}
		}

		
		void rev(){
			if(root==NULL) return;
			string *a=toArray();
			int i=0;
			Node *start=root;
			while(i<length){
				start->data=a[length-i-1];
				i++;
				start=start->next;
			}
		}
		void danhSachTuVaSoLanXuatHien(){
			int *sl=new int[length];
			string *s=new string[length];
			int n=0;
			int k=0;
			Node *start=root;
			while(k<length){
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
				k++;
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
		a.addFirst(s);
	}
	a.danhSachTuVaSoLanXuatHien();
}
