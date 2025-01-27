#include <iostream>
#include "matrix.h"

int m_error(std::string message)
{
    //This is where I would put my different error codes... if I had any
	std::cerr << message;
	return 1;
}

//section .CONSTRUCTORS
Matrix::Matrix()
{
	n = 3;
    m = 3;
    values = new double*[n];
    for(int i = 0; i < n; i++)
    {
        values[i] = new double [m];
        for(int j = 0; j < m; j++)
        {
            values[i][j] = 0;
            if(i == j) values[i][j] = 1;
        }
    }
}
Matrix::Matrix(int nn, int mm)
{
    n = nn;
    m = mm;
    values = new double*[n];
    for(int i = 0; i < n; i++)
    {
        values[i] = new double [m];
        for(int j = 0; j < m; j++)
        {
            values[i][j] = 0;
            if(i == j) values[i][j] = 1;
        }
    }
}
Matrix::Matrix(int nn, int mm, double** a)
{
    n = nn;
    m = mm;
    for(int i = 0; i < n; i++)
    {
        values[i] = new double [n];
        for(int j = 0; j < m; j++)
        {
            values[i][j] = a[i][j];
        }
    }
}
Matrix::~Matrix()
{
    for(int i = 0; i < n; i++)
    {
        delete [] values[i];
    }
    delete [] values;
}

//.section HELPER FUNCTIONS
void Matrix::m_write()
{
    for(int i = 0; i < n; i++)
    {
        std::cout << "enter " << n << " values for the " << i << " row: ";
        
        for(int j = 0; j < n; j++)
        {
            std::cin >> values[i][j];
        }
    }
}

void Matrix::m_print()
{
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << values[i][j] << " ";
        }
        std::cout << "\n";
    }
}


//section .INCREMENTATION .DECREMENTATION
Matrix& Matrix::operator++ ()
{
    if(n != m) return *this;
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) values[i][j]++;
        }
    }
	return *this;
}
Matrix Matrix::operator++ (int)
{
    if(n != m) return *this;
	Matrix tmp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tmp.values[i][j] = values[i][j];
            if(i == j) tmp.values[i][j]++;
        }
    }
	return tmp;
}
Matrix& Matrix::operator-- ()
{
    if(n != m) return *this;
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) values[i][j]--;
        }
    }
	return *this;
}
Matrix Matrix::operator-- (int)
{
    if(n != m) return *this;
	Matrix tmp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tmp.values[i][j] = values[i][j];
            if(i == j) tmp.values[i][j]--;
        }
    }
	return tmp;
}

Matrix& Matrix::operator=(Matrix a)
{
	n = a.n;
    for(int i = 0; i < n; i++)
    {
        values[i] = new double [n];
        for(int j = 0; j < m; j++)
        {
            values[i][j] = a.values[i][j];
        }
    }
	return *this;
}

//section .ADDITION
Matrix Matrix::operator+(Matrix a)
{
	if(a.n != n) 
    {
        m_error("uncompatible matrixes");
        return *this;
    }
    Matrix result(n,m);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            result.values[i][j] += a.values[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator+(int a)
{
	Matrix result(n, m);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == j) result.values[i][j] += a;
        }
    }
    return result;
}

//section .SUBSTRACTION
Matrix Matrix::operator-(Matrix a)
{
	if(a.n != n || a.m != m) 
    {
        m_error("uncompatible matrixes");
        return *this;
    }
    Matrix result(n, m);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            result.values[i][j] -= a.values[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator-(int a)
{
	Matrix result(n, m);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == j) result.values[i][j] -= a;
        }
    }
    return result;
}

//section .MULTIPLICATION
Matrix Matrix::operator*(Matrix a)
{
    if(n != a.m && m != a.n)
    {
        m_error("niepoprawne wielkosci macierzy");
        return *this;
    }
    int nn = (n > a.n)? n : a.n;
    int mm = (m > a.m)? m : a.m;
	Matrix result(nn,mm);
    //TODO
}

double Matrix::determinant()
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        double subsum = 1;
        for(int j = 0; j < n; j++)
        {
            subsum *= values[j%n][(i+j)%m];
        }
        sum += subsum;
    }
    for (int i = 0; i < m; i++)
    {
        double subsum = 1;
        for(int j = 0; j < n; j++)
        {
            subsum *= values[j%n][(m+m-j-1)%m];
        }
        sum -= subsum;
    }
    return sum;
}