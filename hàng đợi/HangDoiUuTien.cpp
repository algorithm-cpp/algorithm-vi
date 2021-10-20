#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	int uutien;
};
bool dk(Node a, Node b){
	return a.data>b.data;
}
class Queue{
	public:
		Node *queue;
		int maxLength=0;
		int length=0;
		void init(int length){
			queue=new Node[length];
			maxLength=length;
		}
		int isEmpty(){
			return length==0;
		}
		int isFull(){
			return length==maxLength-1;
		}
		int size(){
			return length;
		}
		int front(){
			if(length>0){
				int data= queue[0].data;
				for(int i=0;i<length;i++){
					queue[i]=queue[i+1];
				}
				length--;
				return data;
			}
		}
		void push(int data, int uutien){
			Node temp;
			temp.data=data;
			temp.uutien=uutien;
			if(length<maxLength-1){
				queue[length++]=temp;
				sort(queue, queue+length, dk);
			}else{
				cout<<"full"<<endl;
			}
		}
};
Queue q;
void menu(){
	int key;
	while(true){
		cout<<endl<<"0. Khoi tao hang doi"<<endl;
		cout<<"1. kiem tra tinh rong cua hang doi"<<endl;
		cout<<"2. kiem tra tinh day cua hang doi"<<endl;
		cout<<"3. lay kich thuong hang doi"<<endl;
		cout<<"4. lay phan tu dau hang doi"<<endl;
		cout<<"5. dua phan tu vao dau hang doi"<<endl;
		cout<<"chon: ";
		cin>>key;
		switch(key){
			case 0:{
				system("cls");
				int a;
				cout<<"Nhap so phan tu hang doi: ";
				cin>>a;
				q.init(a);
				cout<<"Khoi tao thanh cong!"<<endl; 
				break;
			}
			case 1:{
				system("cls");
				if(q.isEmpty()) cout<<"Hang doi rong"<<endl;
				else cout<<"Hang doi khong rong"<<endl;
				break;
			}
			case 2:{
				system("cls");
				if(q.isFull())	
					cout<<"hang doi day"<<endl;
				else
					cout<<"hang doi chua day"<<endl;
				break;
			}
			case 3:{
				system("cls");
				cout<<"kich thuoc hang doi: "<<q.size()<<endl;
				break;
			}
			case 4:{
				system("cls");
				cout<<"Phan tu dau hang doi: ";
				if(!q.isEmpty()){
					cout<<q.front()<<endl;
				}
				else cout<<"null"<<endl;
				break;
			}
			case 5:{
				system("cls");
				int data, uutien;
				cout<<"Nhap phan tu can them: ";
				cin>>data;
				cout<<"Nhap do uu tien: ";
				cin>>uutien;
				if(!q.isFull()){
					q.push(data,uutien);
				}else{
					cout<<"hang doi day"<<endl;
				}
				break;
			}
		}
	}
}
main(){
	menu();
}
