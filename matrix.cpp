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
    for(int i = 0; i < n; i++)
    {
        values[i] = new double [n];
        for(int j = 0; j < n; j++)
        {
            values[i][j] = 0;
            if(i == j) values[i][j] = 1;
        }
    }
}
Matrix::Matrix(int m)
{
    n = m;
    for(int i = 0; i < n; i++)
    {
        values[i] = new double [n];
        for(int j = 0; j < n; j++)
        {
            values[i][j] = 0;
            if(i == j) values[i][j] = 1;
        }
    }
}
Matrix::Matrix(int m, double** a)
{
    n = m;
    for(int i = 0; i < n; i++)
    {
        values[i] = new double [n];
        for(int j = 0; j < n; j++)
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
        for(int j = 0; j < n; j++)
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
        return 1;
    }
    Matrix result(n);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            result.values[i][j] += a.values[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator+(int a)
{
	Matrix result(n);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) result.values[i][j] += a;
        }
    }
    return result;
}

//section .SUBSTRACTION
Matrix Matrix::operator-(Matrix a)
{
	if(a.n != n) 
    {
        m_error("uncompatible matrixes");
        return 1;
    }
    Matrix result(n);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            result.values[i][j] -= a.values[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator-(int a)
{
	Matrix result(n);
    result = *this;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) result.values[i][j] -= a;
        }
    }
    return result;
}

//section .MULTIPLICATION
Matrix Matrix::operator*(Matrix a)
{
	return a;
}

