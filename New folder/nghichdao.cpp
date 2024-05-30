#include <bits/stdc++.h>
using namespace std;
 
int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}

/*
X la gia tri ma khi lay phan du cua X voi M 
nhan voi phan du cua A voi M sau do lay 
phan du cua phep nhan chia cho M ket qua 
bang 1 tuc la X la nghich dao cua A trong mudulo M
*/ 

int main()
{
    int A = 7, M = 26;
    cout << "nghich dao cua A voi modulo M la :"<<modInverse(A, M);
    return 0;
}
