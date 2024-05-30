#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

// gcd
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// nghich dao modular
int modInverse(int e, int phi)
{
    int t = 0, newt = 1;
    int r = phi, newr = e;

    while (newr != 0)
    {
        int quotient = r / newr;
        int temp = t;
        t = newt;
        newt = temp - quotient * newt;
        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }

    if (r > 1)
        return -1; // return -1 neu ko co nghich dao
    if (t < 0)
        t = t + phi;

    return t;
}

// ktra so nguyen to
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// tao so nguyen to ngay nhien trong [min, max]
int generatePrime(int min, int max)
{
    int num;
    do
    {
        num = min + rand() % (max - min + 1);
    } while (!isPrime(num));
    return num;
}

// luy thua
int modExp(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    srand(time(0));

    wstring key = L"aáàạảãăắằặẳẵâấầậẩẫbcdđeéẹẻẽêếềệểễfghiíìịỉĩjklmnoóòọỏõôốồộổỗơớờợởỡpqrstuúùụủũưứừựửữvwxyýỳỵỷỹ0123456789- ";
    // wstring key = L"abcdefghijklmnopqrstuvwxyz0123456789";

    // Tao anh xa giua ki tu va so nguyen
    std::unordered_map<wchar_t, int> char_to_int;
    std::unordered_map<int, wchar_t> int_to_char;
    for (int i = 0; i < key.size(); ++i)
    {
        char_to_int[key[i]] = i;
        int_to_char[i] = key[i];
    }

    // tao so nguyen to p q
    int p = generatePrime(100, 300);
    int q = generatePrime(100, 300);
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // tao khoa cong khai e
    int e;
    do
    {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    // tao khoa bi mat d
    int d = modInverse(e, phi);

    std::cout << "khoa cong khai: (" << e << ", " << n << ")\n";
    std::cout << "khoa bi mat: (" << d << ", " << n << ")\n";

    std::wstring message;
    wcout << "input message: ";
    getline(wcin, message);

    // Ma hoa
    std::vector<int> cipher;
    wstring tca = L"";
    wcout << "thong diep ma hoa: ";
    for (wchar_t x : message)
    {
        int m = char_to_int[x];
        int c = modExp(m, e, n);
        cipher.push_back(c);
        // tca += int_to_char[c];
        // wcout << c << " ";
        //  wcout << int_to_char[c];
        tca += key[c % key.length()];
    }
    // for (int i = 0; i < cipher.size(); i++)
    // {
    //     tca += key[cipher[i]];
    // }
    wcout << tca << "\n";

    // giai ma
    wstring cache1 = L"";
    wcout << "thong diep da giai ma: ";
    for (int i = 0; i < cipher.size(); ++i)
    {
        int c = cipher[i];
        int m = modExp(c, d, n);

        cache1 += key[m];
        //   std::wcout << int_to_char[m];
    }
    wcout << cache1 << "\n";

    return 0;
}
