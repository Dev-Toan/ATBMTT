#include<iostream>
using namespace std;

int modulo(int bin[], int& size, int a, int b, int n){//a^b mod n

	while(b > 0){
		bin[size++] = b % 2;
		b /= 2;
	}
	
	int f = 1;
	for(int i = size - 1; i >= 0; i--){
		f = (f*f) % n;
		if(bin[i] == 1){
			f = (f*a) % n;
		}
		cout << f << endl;
	}
	return f;

} 

int main(){
	
	int bin[100], size = 0;
	
	cout << modulo(bin, size, 1394, 2011, 3127) << endl;
	for(int i = 0; i < size; i++)
		cout << bin[i] <<" ";
	
	return 0;
}