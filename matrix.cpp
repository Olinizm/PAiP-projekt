#include <iostream>
#include "matrix.h"

int m_error(std::string message)
{
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
Matrix::Matrix(int n)
{
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
Matrix::Matrix(int n, double** a)
{
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
    delete [] values;
}

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

void m_print(Matrix m)
{
	for(int i = 0; i < m.n; i++)
    {
        for(int j = 0; j < m.n; j++)
        {
            std::cout << m.values[i][j] << " ";
        }
        std::cout << "\n";
    }
}

//section .INCREMENTATION .DECREMENTATION
Matrix& Matrix::operator++ ()
{
	
	return *this;
}
Matrix Matrix::operator++ (int)
{
	Matrix tmp;
	return tmp;
}
Matrix& Matrix::operator-- ()
{
	
	return *this;
}
Matrix Matrix::operator-- (int)
{
	Matrix tmp;
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
	
}
Matrix Matrix::operator+(int a)
{
	
}

//section .SUBSTRACTION
Matrix Matrix::operator-(Matrix a)
{
	
}
Matrix Matrix::operator-(int a)
{
	
}

//section .MULTIPLICATION
Matrix Matrix::operator*(Matrix a)
{
	
}

