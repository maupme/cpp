#include <iostream>

using namespace std;

int b[4] = {0};

int hashFunc1(int data){
	return data % 4;
}

int probing(int h){
	int i=0;
	i = (h+1)%4;
	while(b[i]!=0){
		i = i++%4;
	}
	return i;
}

void hashing(int data){
	int h = hashFunc1(data);
	if(b[h]==0){
		b[h]=data;
	}
	else{
		b[probing(h)] = data;
	}
}

int main(){
	int a[] = {10,5,6,7};
	
	
	for(int i = 0; i < 4; i++){
		hashing(a[i]);		
	}
	
	//tampil array hasil
	for(int i = 0; i < 4; i++){
		cout<<b[i]<<" ";
	}
}
