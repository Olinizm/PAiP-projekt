#pragma once
//Definicja macierzy
class Matrix
{
    int n,m; //wielkość macierzy
	double **values; //wartości w macierzy

public:

//konstruktory

    //tworzy macierz jednościową 3x3
	Matrix();
    //tworzy macierz nxm jeśli n=m jest ona jednościowa
	Matrix(int n, int m);
    //tworzy macierz nxm z wartościami w tablicy 2-wymiarowej
	Matrix(int n, int m, double**);
    //destruktor
	~Matrix();


//funkcje pomocnicze

	//wpisywanie wartości do macierzy
	void m_write();
    //wyświetla wartości w macierzy
	void m_print(); 

//operacje na macierzach

    //zwiększa wartość macierzy o macierz jednościową 1
	Matrix& operator++ ();
	Matrix operator++ (int);

    //zmniejsza wartość macierzy o macierz jednościową 1
	Matrix& operator-- (); 
	Matrix operator-- (int); 

	Matrix& operator= (Matrix); 

	Matrix operator+ (Matrix); 
	Matrix operator+ (int); 
	Matrix operator- (Matrix); 
	Matrix operator- (int); 

	Matrix operator* (Matrix); 

	//odwracanie macierzy
	void reverse();
	//obliczanie wyznacznika
	double determinant();
};