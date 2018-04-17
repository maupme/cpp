#include <iostream>
using namespace std;

int heap[] = {10,20,30,40,1,2,3,4,5,15,25,35,31,32};
int length = sizeof(heap)/sizeof(heap[0]);
int indexterakhir = length-1;
	
int induk(int k){
	int j = (k - 1)/2;
	return j; 
}
int saudara(int anak){
	int y = induk(anak)*2+1;
	if(heap[y]!=0){
		if(y == anak){
			if(heap[y+1]<=indexterakhir)
			{
				y = y+1;
			}
		}
	}
	return y;
}
int mak(int a, int b){
	if(heap[a]>heap[b]){
		return a;
	}
	else{
		return b;
	}
}
bool punyaanak(int i){
	if((2*i+1)<=indexterakhir){
		return 1;
	}
	else{ return 0; }
}


void konversiheap(){
	int i = indexterakhir;
	while(i!=0){
		int m = mak(i,saudara(i));
		if(heap[induk(i)] < heap[m]){
			swap(heap[induk(i)],heap[m]);
			
			cout<<"index "<<m<<" tukar dengan induknya"<<endl;
			
			if(punyaanak(m)){
				cout<<m<<" punya anak ";
			}

			int temp = m;
			while(punyaanak(temp)==1){
				int anak1, anak2;
				anak1 = temp*2+1;
				anak2 = temp*2+2;
				int makanak1anak2 = mak(anak1,anak2);
				
				cout<<anak1<<" dan "<<anak2<<endl;
				
				if(heap[temp]< heap[makanak1anak2]){
					swap(heap[temp],heap[makanak1anak2]);
					temp=makanak1anak2;
				}
				else{
					break;
				}
				
			}
			
		}
		i--;
	}
}


int main(){
	konversiheap();
	
	for(int k = 0; k<length; k++){
		cout<<heap[k]<<" ";
	}
}
