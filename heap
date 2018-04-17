#include <iostream>
using namespace std;

int i = 0;
int induk(int k){
	int j = (k - 1)/2;
	return j; 
}
void maxheap(int a[], int n){
	if(a[0]==0){
		a[0] = n;
		i++;
	}
	else{
		a[i] = n;
		int temp = i;
		while(a[temp]>a[induk(temp)]){
			swap(a[temp],a[induk(temp)]);
			temp = induk(temp);
		}
		i++;
	}
}

int main(){
	int heap[14];
	int bil;
	cout<<"masukkan data int, ketik 0 untuk exit"<<endl;
	while(bil!=0)
	{
		cin>>bil;
		if(bil!=0){
			maxheap(heap,bil);
		}		
	}
	//maxheap(heap,13);
	//return 0;
	for(int k = 0; k<15; k++){
		cout<<heap[k]<<" ";
	}
}
