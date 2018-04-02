#include <iostream>
using namespace std;

struct node {
	int data; //deklarasi variabel data
	node *next; //deklarasi pointer next
};

int jmlnode = 0;
node *start = new node;

void Tampilkan()
{
	node *temp;
	temp = start;
	if(start == NULL)
            cout<<"\ntidak ada data dalam linked list"<<endl;
    else
    {
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
}
void TambahData(int data,int posisi)
{	
	node *newnode = new node;
	newnode->data=data;
	newnode->next=NULL;
	
	//sisipkan node di awal
	if(posisi==1){
		if(start==NULL){
			start = newnode;
		}
		else{
			newnode->next =start;
			start = newnode;
		}
	}
	
	//sisipkan node di tengah
	else if(posisi>1&&posisi<=jmlnode){
		node * temp;
		node* after;
		temp = start;
		for(int i=1;i<posisi-1;i++){
			temp=temp->next;
		}
		after = temp->next;
		temp->next = newnode;
		newnode->next = after;	
	}
	
	//sisipkan node di akhir
	else if(posisi>jmlnode){
		node * temp;
		temp = start;
		if(temp==NULL){
			start = newnode;
		}
		else{
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	else{
		cout<<"Error: posisi node diawali dari 1"<<endl; 
	}
	jmlnode++;
}

void HapusData(int data)
{
	node *temp;
	node *nodehapus;
	temp = start;
	if(start == NULL)
            cout<<"\ntidak ada data dalam linked list"<<endl;
    else
    {
		//jika jumlah node hanya 1 maka langsung dihapus node pertama
		if(jmlnode==1)
		{
			if(start->data==data)
			{
				delete(start);
				start = NULL;
				jmlnode--;
			}
		}
		//jika lebih dari 1 nodenya
		else{
			temp=start;
			while(temp->next!=NULL&& temp->next->data!=data)
			{
				temp=temp->next;
			}
			//menghapus node ditengah
			if(temp->next!=NULL){
				nodehapus=temp->next;
				temp->next=nodehapus->next;
				delete(nodehapus);
				jmlnode--;
			}
			//menghapus node diawal
			else if(start->data==data){
				temp=start;
				start=temp->next;
				delete(temp);
				jmlnode--;
			}
		}
	}
}

int main(){

	cout<<"+--------------------------------+"<<endl;
	cout<<"|       PROGRAM LINKEDLIST       |"<<endl;
	cout<<"|   Ma'ruf Aminudin / Pra S2 B   |"<<endl;
	cout<<"+--------------------------------+"<<endl;
	//int posisi,data;
	
	//node *start = new node;
	start->data = 10;
	jmlnode++;
	start->next = new node;
	start->next->data = 20;
	jmlnode++;
	start->next->next = new node;
	start->next->next->data = 30; 
	jmlnode++;
	start->next->next->next = NULL;
	
	//menyisipkan diantara node 1 dan 2
	node *temp,*baru;
	baru = new node;
	baru->data = 15;
	temp = start;
	baru->next = temp->next;
	start->next = baru;
	jmlnode++;
	
	//menyisipkan di awal {5,next}
	node *baru2 = new node;
	baru2->data = 5; 
	baru2->next = start;
	start = baru2;
	jmlnode++;
	
	TambahData(35,1);
	TambahData(45,3);
	TambahData(50,5);
	TambahData(55,6);
	
	HapusData(20);
	
	HapusData(45);
	HapusData(15);
	TambahData(15,3);
	TambahData(45,7);
	
	
	Tampilkan();
	
}
