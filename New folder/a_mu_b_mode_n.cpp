#include <iostream>
using namespace std;
 
int power(int a, int b, int n)
{
 
    // khoi tao bien f
    int f = 1;
 
    // ktra xem y nhan gia tri 0 hay ko
    while (b > 0) {
 
        // neu y le thi nhan x voi ket qua
        if (b % 2 == 1)
            f = (f * a);
 
        // y = y/2 phep dich bit sang phai
        b = b >> 1;
 
        // Change x to x^2
        a = (a * a);
    }
    return f % n;
}
 
int main()
{
    int a = 21;
    int b = 7;
    int n = 209;
    cout << "Power is " << power(a, b, n);
    return 0;
}
