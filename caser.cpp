#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

wstring key = L"aáàạảãăắằặẳẵâấầậẩẫbcdđeéẹẻẽêếềệểễfghiíìịỉĩjklmnoóòọỏõôốồộổỗơớờợởỡpqrstuúùụủũưứừựửữvwxyýỳỵỷỹ0123456789- ";

wstring mahoa(int n, wstring text)
{
    wstring cache = L"";

    for (wchar_t &x : text)
    {
        int i = (key.find(x) + n) % key.length();
        cache += key[i];
    }

    return cache;
}

wstring giaima(int n, wstring text)
{
    // wstring cache = L"";

    // for (wchar_t& x : text) {
    //	int i = (key.find(x) - n + key.length()) % key.length();
    //	cache += key[i];
    // }

    return mahoa(-n + key.length(), text);
}

void output(int n, wstring text)
{
    wcout << "chuoi goc: " << text << endl;
    wcout << "chuoi ma hoa: " << mahoa(n, text) << endl;
    wcout << "chuoi giai ma: " << giaima(n, text) << endl;
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    output(5, L"ỉêòòõạỷĩỏảẹỉắõảỳĩhủảỏãọảàà5");

    return 0;
}
