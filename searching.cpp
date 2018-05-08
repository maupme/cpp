#include <iostream>
#include <math.h>

using namespace std;

int data[] =  {1,2,4,5,7,8,10,16,23,24,27,38,40,47,62,73,75,81,87,94};
int panjang = sizeof(data)/sizeof(*data);

void linearSearch(int x,int i,int l){
	bool ketemu = false;
	//int i = 0;
	for(i;i < l;i++){
		if(data[i]==x){
			ketemu = true;
			break;
		}
	}
	if(ketemu){
		cout<<"data ditemukan pada index ke "<<i<<endl;
	}
	else{
		cout<<"data tidak ditemukan"<<endl;
	}
}

void jumpSearch(int x){
	//int jml = 5;
	int n = 0;
	int Bi = data[n];
	while(x>Bi){		
		if(n==panjang){
			n=panjang-1;
			Bi = data[n];
			break;
		}
		else{
			n = n+4;
			Bi = data[n];
		}
		
	}
	if(Bi>x){
		n=n-4;
		cout<<"mau nyari nilai, n = "<<n<<endl;
		linearSearch(x,n,4);
	}
	else if(Bi == x){
		cout<<"data ditemukan pada index ke "<<n<<endl;
	}
	else{
		cout<<"data tidak ditemukan"<<endl;
	}
}

void binarySearch(int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        if (data[mid] == x)  
            //return mid;
 			cout<<"data ditemukan pada index ke "<<mid<<endl;
        if (data[mid] > x) 
            binarySearch(l, mid-1, x);
 
        binarySearch(mid+1, r, x);
   }

}

int main(){
	int index = 0;
	/*linearSearch(7,0,panjang);
	linearSearch(94,0,panjang);
	linearSearch(100,0,panjang);
	jumpSearch(7);
	jumpSearch(94);
	jumpSearch(100);*/
	//binarySearch1(27,index,panjang);
	//binarySearch1(62,index,panjang);
	binarySearch(0, panjang-1, 100);
	//int result = binarySearch(0, panjang-1, 7);
	//cout<<"data ditemukan pada index ke "<<result<<endl;
}
