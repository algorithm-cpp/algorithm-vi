#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct Node{
	int data;
	int uutien;
	Node *next=NULL;
};
class Queue{
	public:
		Node *first=NULL;
		Node *end=NULL;
		int length=0;
		int isEmpty(){
			return first==NULL;
		}
		int size(){
			return length;
		}
		void push(int data, int uutien){
			Node *temp=new Node;
			temp->data=data;
			temp->uutien=uutien;
			if(first==NULL){
				first=temp;
				end=temp;
				length++;
				return;
			}
			Node *start= first, *front=NULL;
			while(start!=NULL && start->uutien < uutien){
				front=start;
				start=start->next;
			}
			if(front==NULL){
				temp->next=first;
				first=temp;
				length++;
				return;
			}
			front->next=temp;
			temp->next=start;
			length++;
		}
		int front(){
			return first->data;
		}
		void pop(){
			first=first->next;
			length--;
		}
		
};
Queue q;
void menu(){
	int key;
	while(true){
		cout<<"1. kiem tra tinh rong cua hang doi"<<endl;
		cout<<"2. lay kich thuong hang doi"<<endl;
		cout<<"3. lay phan tu dau hang doi"<<endl;
		cout<<"4. dua phan tu vao dau hang doi"<<endl;
		cout<<"chon: ";
		cin>>key;
		switch(key){
			case 1:{
				system("cls");
				if(q.isEmpty())	
					cout<<"hang doi rong"<<endl;
				else
					cout<<"hang doi khong rong"<<endl;
				break;
			}
			case 2:{
				system("cls");
				cout<<"kich thuoc hang doi: "<<q.size()<<endl;
				break;
			}
			case 3:{
				system("cls");
				cout<<"Phan tu dau hang doi: ";
				if(!q.isEmpty()){
					cout<<q.front()<<endl;
					q.pop();
				}
				else cout<<"null"<<endl;
				break;
			}
			case 4:{
				system("cls");
				int data, uutien;
				cout<<"Nhap phan tu can them: ";
				cin>>data;
				cout<<"Nhap do uu tien: ";
				cin>>uutien;
				q.push(data, uutien);
				break;
			}
		}
	}
}
main(){
	menu();
}
