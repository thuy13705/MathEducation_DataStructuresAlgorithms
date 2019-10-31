#pragma once
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Matrix
{
private:
	int m, n;//so dong, so cot cua ma tran.
	float **a;//mang dong luu mang hai chieu
private:
	//Ham tim ma tran bac thang.
	Matrix &EchelonMatrix();
public:
	//Phuong thuc khoi tao ma tran mac dinh.
	Matrix();
	//Phuong thuc khoi tao ma tran voi so dong so cot cho san.
	Matrix(int sd, int sc);
	//Phuong thuc khoi tao sao chep.
	Matrix(const Matrix &b);

	//Cac getter/setter.
	int M();
	int N();
	void getM(int value);
	void getN(int value);

	//Phuong thuc huy
	~Matrix();
public:
	//Kiem tra co phai la ma tran vuong khong.
	int checkSquareMatrix();

	//Ham nhap ma tran.
	void GetArray();
	//Ham xuat ma tran
	void PrintArray();

	//Ham gan voi mot ma tran cho truoc.
	Matrix &operator=(const Matrix &b);

	//Ham tinh dinh thuc ma tran.
	float DetMatrix();
	//Tim ma tran nghich dao.
	Matrix InverseMatrix();
	//Nhan hai ma tran.
	Matrix MultiplyMatrix(const Matrix &b);
	//Tim hang ma tran.
	int RankMatrix();
	//Giai he phuong trinh tuyen tinh.
	int SolveLinearEquationMatrix();
};
