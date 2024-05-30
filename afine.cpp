#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

wstring key = L"aáàạảãăắằặẳẵâấầậẩẫbcdđeéẹẻẽêếềệểễfghiíìịỉĩjklmnoóòọỏõôốồộổỗơớờợởỡpqrstuúùụủũưứừựửữvwxyýỳỵỷỹ0123456789- ";
// wstring key = L"abcdefghijklmnopqrstuvwxyz";

wstring mahoa(int a, int b, wstring text)
{
	wstring cache = L"";

	for (wchar_t &x : text)
	{
		int i = (a * key.find(x) + b) % key.length();
		cache += key[i];
	}

	return cache;
}

wstring giaima(int a, int b, wstring text)
{
	wstring cache = L"";

	int n = 0;
	for (int i = 0; i < key.length(); i++)
	{
		if ((a * i) % key.length() == 1)
		{
			n = i;
			break;
		}
	}

	for (wchar_t &x : text)
	{
		int i = (n * (key.find(x) - b + key.length())) % key.length();
		cache += key[i];
	}

	return cache;
}

void output(int a, int b, wstring text)
{
	wcout << "khoa (a,b): " << a << "," << b << endl;
	wcout << "chuoi goc: " << text << endl;
	wcout << "chuoi ma hoa: " << mahoa(a, b, text) << endl;
	wcout << "chuoi giai ma: " << giaima(a, b, text) << endl;
}

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	output(5, 3, L"êulẩớê-ãự7-ịễấê");
}