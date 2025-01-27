#include <iostream>
#include <vector>
#include <stdlib.h> 
#include "matrix.h"

//Made by Aleksandra C. (Olinizm), full changelog on: https://github.com/Olinizm/PAiP-projekt

using namespace std;

vector<Matrix> M;
int ilosc = 0;

void print_allM()
{
    cout << "Aktualne macierze: \n";
    for(int i = 0; i < ilosc; i++)
    {
        M[i].m_print();
        cout << '\n';
    }
}

int main()
{
    Matrix A;
    M.push_back(A);
    ilosc++;
    char w;
    while(true)
    {
        system("cls");
        cout << "Zarzadzanie macierzami\n";
        cout << "----------------------\n";
        print_allM();
        cout << "----------------------\n";
        cout << "1. Dodaj nowa Macierz\n";
        cout << "2. Operacje na 1 macierzy\n";
        cout << "3. Operacje na 2 macierzach\n";
        cout << "4. Operacje na 3 macierzach\n";
        cin >> w;

        system("cls");
        if(w == '1')
        {
            int n, m;
            cout << "ile wierszy: ";
            cin >> n;
            cout << "ile kolumn: ";
            cin >> m;
            Matrix B(n, m);
            B.m_write();
            M.push_back(B);
            M[1].m_print();
            ilosc++;
        }
        switch (w)
        {
            case '1':
            break;
            case '2':
            cout << "----------------------\n";
            cout << "1. Inkrementacja (dla macierzy nxn)\n";
            cout << "2. Dekrementacja (dla macierzy nxn)\n";
            cout << "3. Oblicznie wyznacznika\n";
            char ch;
            int k;
            cin >> ch;
            print_allM();
            cout << "wybierz macierz (numerowane od 0): ";
            cin >> k;
            switch (ch)
            {
                case '1':
                (++M[k]).m_print();
                break;
                case '2': 
                (--M[k]).m_print();
                break;
                case '3':
                cout << M[k].determinant() << '\n';
            }
            break;
            case '3':
            break;
            case '4':
            break;
            default:
            cout << "niepoprawna komenda \n";
            
            break;
        }
        system("pause");
        
    }
    return 0;
}