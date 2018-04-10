#include <iostream>
using namespace std;

struct node{
	int data;
	node * kanan;
	node * kiri;
	node(){
		data = 0;
		kanan = NULL;
		kiri =NULL;
	};
} * bintree;

struct ret_cari{
	bool ketemu;
	int langkah;
}carilah;

void tambahnode(node *& tree, node *& newnode){
	if(tree==NULL || tree->data==0){
		tree = newnode;
	}
	else{
		if(newnode->data<tree->data){
			tambahnode(tree->kiri, newnode);
		}
		else if(newnode->data>tree->data){
			tambahnode(tree->kanan, newnode);
		}
	}
}

void PRE(node *& T)
{
  if (T!=NULL) {
     cout<<T->data<<" ";
     PRE(T->kiri);
     PRE(T->kanan);
  }
}

ret_cari carinode(node *& tree, int data){
	if(tree!=NULL){
		if(tree->data==data){
			carilah.ketemu = true;
		}
		else{
			if(data<tree->data){
				carilah.langkah++;
				carinode(tree->kiri, data);
			}
			else if(data>tree->data){
				carilah.langkah++;
				carinode(tree->kanan, data);
			}
		}
	}
	return carilah;
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->kiri != NULL)
        current = current->kiri;
 
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->kiri = deleteNode(root->kiri, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->kanan = deleteNode(root->kanan, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->kiri == NULL)
        {
            struct node *temp = root->kanan;
            //delete(root);
            return temp;
        }
        else if (root->kanan == NULL)
        {
            struct node *temp = root->kiri;
            //delete(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->kanan);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->kanan = deleteNode(root->kanan, temp->data);
    }
    return root;
}


int main()
{
	int in,del;
	bintree = new node;
	cout<<"data awal:"<<bintree->data<<endl;
	while(true){
		cout<<"Masukkan bilangan integer positive (0 untuk selesai): ";
		cin>>in;
		if(in>0){
			node * temp = new node;
			temp->data=in;
			tambahnode(bintree, temp);
			cout<<endl;
		}
		else{
			break;
		}
	}
	PRE(bintree);
	cout<<" Ketik Integer positive yang mau dicari: ";
	cin>>in;
	if(in>0){
		ret_cari cari = carinode(bintree, in);
		cout<<"Hasil pencarian: "<<cari.ketemu;
		cout<<" Jumlah langkah pencarian: "<<cari.langkah<<endl;
	}
	cout<<"Ketik Integer positive yang mau dihapus: ";
	cin>>del;
	deleteNode(bintree,del);
	PRE(bintree);
	return 0;
}
