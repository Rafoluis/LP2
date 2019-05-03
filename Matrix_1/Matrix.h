#include<iostream>
#ifndef MATRIX_H
#define MATRIX_H
#include<cassert>
using namespace std;

template<class T>
	class Matrix;

template<class T>
	ostream & operator<<(ostream & os,const Matrix<T> & inf);

template<class T>
class Matrix{
	private:
		T* ptr;
		size_t n_rows,n_colms;
		int r,c;
	public:
		Matrix(size_t nr=0,size_t nc=0);
		Matrix(const Matrix<T> & m);
		size_t g_rows(const Matrix<T> & m)const;
		size_t g_colms(const Matrix<T> & m)const;
		~Matrix();
		Matrix<T> operator + (const Matrix<T> & m);
		Matrix<T> operator * (const Matrix<T> & m);
		T & operator()(size_t i, size_t j);
		Matrix <T> & operator << (const T m);	
};
#include "Matrix.inl"
#endif
