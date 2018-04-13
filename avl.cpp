#include <iostream>
using namespace std;

struct node{
	int data;
	node * kanan;
	node * kiri;
	int height;
	node(){
		data = 0;
		kanan = NULL;
		kiri =NULL;
		height = 0;
	};
} * avl;

int max(int a, int b);
int max(int a, int b)
{
    return (a > b)? a : b;
}


int height(node *& N)
{
	if(N == NULL)
		return -1;
	return N->height;
}

int updateh(node *& N)
{
	N->height = 1 + max(height(N->kiri),height(N->kanan));
	return N->height;
}


int BF(node *& N)
{
    if (N == NULL)
        return 0;
    return height(N->kiri) - height(N->kanan);
}

node* singlekananRotate(node* &t)
{
    node* u = t->kiri;
    t->kiri = u->kanan;
    u->kanan = t;
    t->height = max(height(t->kiri), height(t->kanan))+1;
    u->height = max(height(u->kiri), t->height)+1;
    return u;
}

node* singlekiriRotate(node* &t)
{
    node* u = t->kanan;
    t->kanan = u->kiri;
    u->kiri = t;
    t->height = max(height(t->kiri), height(t->kanan))+1;
    u->height = max(height(t->kanan), t->height)+1 ;
    return u;
}

node* doublekiriRotate(node* &t)
{
    t->kanan = singlekananRotate(t->kanan);
    return singlekiriRotate(t);
}

node* doublekananRotate(node* &t)
{
    t->kiri = singlekiriRotate(t->kiri);
    return singlekananRotate(t);
}


void tambahnode2(node *& tree, node *& newnode){
	if(tree==NULL || tree->data==0){
		tree = newnode;
	}
	
	else if(newnode->data<tree->data){
		tambahnode2(tree->kiri, newnode);
		if(height(tree->kiri) - height(tree->kanan) == 2)
		{
			if(newnode->data < tree->kiri->data)
                tree = singlekananRotate(tree);
            else
				tree = doublekananRotate(tree);
		}
	}
	else if(newnode->data>tree->data){
		tambahnode2(tree->kanan, newnode);
		if(height(tree->kiri) - height(tree->kanan) == -2)
		{
			if(newnode->data > tree->kanan->data)
                tree = singlekiriRotate(tree);
            else
				tree = doublekiriRotate(tree);
		}
	}
	
			
	
	updateh(tree);
}

void pre(node *& T)
{
    if(T != NULL)
    {
       	cout<<T->data<<" ";
        pre(T->kiri);
     	pre(T->kanan);
    }
}

void inorder(node* t)
{
    if(t == NULL)
        return;
    inorder(t->kiri);
    cout << t->data << " ";
    inorder(t->kanan);
}

int main(){
	int in;
	avl = new node;
	cout<<avl->height<<endl;

	while(true){
		cout<<"Masukkan bilangan integer positive (0 untuk selesai): ";
		cin>>in;
		if(in>0){
			node * temp = new node;
			temp->data=in;
			tambahnode2(avl, temp);
			//cout<<avl->height<<endl;
		}
		else{
			break;
		}
	}
	
	cout<<"preorder ";
	pre(avl);
	cout<<endl;
	cout<<"inorder ";
	inorder(avl);
	
	cout<<endl<<"tinggi tree "<<avl->height<<endl;
	cout<<"tinggi kiri "<<height(avl->kiri)<<endl;
	cout<<"tinggi kanan "<<height(avl->kanan)<<endl;
	cout<<"BF tree "<<BF(avl)<<endl;
	cout<<"BF tree kiri "<<BF(avl->kiri)<<endl;
	cout<<"BF tree kanan "<<BF(avl->kanan)<<endl;
}

