#pragma once
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
public:
	//Khoi tao ma tran mac dinh.
	Matrix();
	//Ham khoi tao ma tran voi so dong so cot cho san.
	Matrix(int sd, int sc);
	//Ham sao chep tu mot ma tran khac.
	Matrix(const Matrix &b);
	//Ham huy.
	~Matrix();
private:
	//Ham tim ma tran bac thang.
	Matrix &EchelonMatrix();
public:
	//Kiem tra co phai la ma tran vuong khong.
	int checkSquareMatrix();
	//Ham gan voi mot ma tran cho truoc.
	Matrix &operator=(const Matrix &b);
	//Ham nhap ma tran.
	void GetArray();
	//Ham xuat ma tran
	void PrintArray();
	//Ham tinh dinh thuc ma tran.
	float DetMatrix();
	//Tim ma tran nghich dao.
	Matrix InverseMatrix();
	//Nhan hai ma tran.
	Matrix MultiplyMatrix(const Matrix &b);
	//Tim hang ma tran.
	int RankMatrix();
	//Giai he phuong trinh tuyen tinh.
	int EquationMatrix();
};
