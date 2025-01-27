#pragma once
//Definicja macierzy
class Matrix
{
    const int n; //wielkość macierzy
	double *values[]; //wartości w macierzy

public:

//konstruktory

    //tworzy macierz jednościową 3x3
	Matrix();
    //tworzy macierz jednościową nxn
	Matrix(int n);
    //tworzy macierz nxn z wartościami w tablicy 2-wymiarowej
	Matrix(int n, double**);
    //destruktor
	~Matrix();

//funkcje pomocnicze

    //wyświetla wartości w macierzy
	void m_print(); 
    //wyświetla wartości w macierzy, ale ładniej wygląda w kodzie uwu
	friend void m_print(Matrix); 

//operacje na macierzach

    //zwiększa wartość macierzy o macierz jednościową
	Matrix& operator++ ();
	Matrix operator++ (int);

    //zmniejsza wartość macierzy o macierz jednościową
	Matrix& operator-- (); 
	Matrix operator-- (int); 

	Matrix& operator= (Matrix); 

	Matrix operator+ (Matrix); 
	Matrix operator+ (int); 
	Matrix operator- (Matrix); 
	Matrix operator- (int); 

	Matrix operator* (Matrix); 
	Matrix operator/ (Matrix); 
};