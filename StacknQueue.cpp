#include <iostream>
#include <stack> 
#include <string.h>

using namespace std;
stack<char> mystack;
const int maxq = 5;

struct queue{ 
	char isi[maxq];
    int front,rear;
};

void initqueue(queue &Q){ 
	Q.front =0 ;Q.rear =-1 ;
	for(int i=0;i<maxq;i++) Q.isi[i]=48;
}

void enqueue(queue &Q,char x){ 
	if((Q.isi[(Q.rear+1)%maxq])==48){
		Q.rear++;
		Q.rear=Q.rear % maxq;
		Q.isi[Q.rear ]=x ;
		cout<<"enqueue q["<<Q.rear<<"]="<<x<<endl;
	}
	else cout<<"full\n";
}

void dequeue(queue &Q,char &x){ 
	if(Q.isi[Q.front]==48) cout<<"Empty";
	else{
	   Q.front=Q.front % maxq;
	   x=Q.isi[Q.front] ;
	   Q.isi[Q.front]=48;

	   cout<<"dequeque q["<<Q.front <<"]= "<<x<<endl;
	   cout<<"Isi q["<<Q.front <<"]="<<Q.isi[Q.front]<<endl;
	   Q.front++;
	   //Q.front=(Q.front++)%maxq;
	}
}

void PrintQueue(queue Q)
{
	for(int i=0;i<maxq;i++){
		if(Q.isi[(Q.front+i)%maxq]!= 48){
			cout<<Q.isi[(Q.front+i)%maxq]<<" ";
		}
	}
	cout<<endl;
}

void olah(){    
  char x,y[]={'U','G','M','J','U','A','R','A','1'}; 
  queue Q;
  initqueue(Q);
  for(int i=0;i<=8;i++) if(y[i]<75) enqueue(Q,y[i]);
  dequeue(Q,x);
  enqueue(Q,'O');
  dequeue(Q,x);
  enqueue(Q,'K');
  dequeue(Q,x);
  enqueue(Q,'E'); 
  dequeue(Q,x);
  enqueue(Q,'Y');
  enqueue(Q,'A');
  PrintQueue(Q);
  
  cout<<"isi aray dari index 0 sampai 4"<<endl;
  for(int i=0;i<5;i++){
	  cout<<Q.isi[i]<<" ";
  }
}


void palindrom(char kata[]){
	int l = strlen(kata);
	for(int i=0;i<l;i++){
		mystack.push(kata[i]);
	}
	mystack.push(32);
	for(int i=l-1;i>=0;i--){
		mystack.push(kata[i]);
	}
	while (!mystack.empty())
	{
		cout << mystack.top();
		mystack.pop();
	}
	cout<<endl;
}


int main(){
	cout<<"Tugas Nomor 1------------------"<<endl;
	char kata1[] = "saya"; palindrom(kata1);
	char kata2[] = "kasur"; palindrom(kata2);
	char kata3[] = "12345"; palindrom(kata3);
	cout<<endl;
	cout<<"Tugas Nomor 2------------------"<<endl;
	olah();
	
}
