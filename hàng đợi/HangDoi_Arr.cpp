#include <iostream>
#include <stdlib.h>
using namespace std;
class Queue{
	public:
		int *queue=NULL;
		int length=0;
		int maxLength=1;
		void init(int length){
			queue=new int[length];
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
			return queue[0];
		}
		int pop(){
			if(length>0){
				int data=queue[0];
				for(int i=0;i<length;i++){
					queue[i]=queue[i+1];
				}
				length--;
				return data;
			}else{
				cout<<"null"<<endl;
			}
		}
		void push(int data){
			if(length<maxLength-1){
				queue[length]=data;
				length++;
			}else{
				cout<<"full"<<endl;
			}
		}
};
Queue q;
void menu(){
	int key;
	while(true){
		cout<<endl<<"1. Khoi tao hang doi"<<endl;
		cout<<"2. kiem tra tinh day cua hang doi"<<endl;
		cout<<"3. lay kich thuong hang doi"<<endl;
		cout<<"4. lay phan tu dau hang doi"<<endl;
		cout<<"5. dua phan tu vao dau hang doi"<<endl;
		cout<<"chon: ";
		cin>>key;
		switch(key){
			case 1:{
				system("cls");
				int a;
				cout<<"Nhap so phan tu hang doi: ";
				cin>>a;
				q.init(a);
				cout<<"Khoi tao thanh cong!"<<endl; 
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
					cout<<q.pop()<<endl;
				}
				else cout<<"null"<<endl;
				break;
			}
			case 5:{
				system("cls");
				int data;
				cout<<"Nhap phan tu can them: ";
				cin>>data;
				if(!q.isFull()){
					q.push(data);
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
