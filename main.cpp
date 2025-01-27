#include <iostream>
#include "matrix.h"

//Made by Aleksandra C. (Olinizm), full changelog on: https://github.com/Olinizm/PAiP-projekt

using namespace std;

int main()
{
    Matrix A(3);
    ++A;
    A.m_write();
    A.m_print();
    return 0;
}