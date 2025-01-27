#include <iostream>
#include <vector>
#include "matrix.h"

//Made by Aleksandra C. (Olinizm), full changelog on: https://github.com/Olinizm/PAiP-projekt



using namespace std;

int main()
{
    vector<Matrix> M;
    Matrix A;
    M.push_back(A);
    int ilosc = 1;
    char w;
    while(true)
    {
        cout << "Zarzadzanie macierzami\n";
        cout << "----------------------\n";
        cout << "aktualne macierze:\n";
        for(int i = 0; i < ilosc; i++)
        {
            M[i].m_print();
        }
        cout << "----------------------\n";
        cout << "1. Dodaj nowa Macierz\n";
        cout << "2. Operacje na 1 macierzy\n";
        cout << "3. Operacje na 2 macierzach\n";
        cout << "4. Operacje na 3 macierzach\n";
        w = getchar();
    }
    return 0;
}