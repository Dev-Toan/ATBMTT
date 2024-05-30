#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(a % b == 0) return b;
	return gcd(b, a%b);
}

int soNghichDao(int a, int n){
	int r, q, x, tmp, x0 = 0, x1 = 1;
	while(a > 0){
		r = n % a;
		q = n / a;
		if(r == 0) break;
		x = x0 - q*x1;
		n = a;
		a = r;
		x0 = x1;
		x1 = x;
	}
	if(x >= 0) return x;
	return x + tmp;
}

int main(){
	int result = gcd(550, 1759);
	cout << result << endl;
	if(result == 1){
		int ketqua = soNghichDao(550, 1759);
		cout << ketqua << endl; 
	}
	else{
		cout << "khong ton tai phan tu nghich dao" << endl;
		
	}
	return 0;
}