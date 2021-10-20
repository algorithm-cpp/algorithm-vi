#include <iostream>
using namespace std;

class Queue{
	private:
		int *root=NULL;
		int length=0;
		int maxLength=0;
		
	public:
		void init(int l){
			root=new int[l];
			maxLength=l;
		}
		int isFull(){
			return length==maxLength-1;
		}
		int isEmpty(){
			return length==0;
		}
		int size(){
			return length;
		}
		void push(int data){
			if(root==NULL){
				cout<<"null"<<endl;
				return;
			}
			if(length<maxLength-1){
				root[length]=data;
				length++;
			}else{
				cout<<"full"<<endl;
			}
		}
		int front(){
			return root[0];
		}
		void pop(){
			if(root==NULL){
				cout<<"null"<<endl;
				return;
			}
			if(length==0){
				cout<<"khong the pop. hang doi rong"<<endl;
				return;
			}
			for(int i=0;i<length;i++){
				root[i]=root[i+1];
			}
			length--;
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
		cout<<"5. dua phan tu vao hang doi"<<endl;
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
					cout<<q.front()<<endl;
					q.pop();
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
