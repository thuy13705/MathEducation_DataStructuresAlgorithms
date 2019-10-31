#pragma once
#include<iostream>
#include<math.h>

using namespace std;

struct Vector {
	int n;	//so luong phan tu cua vector
	float vec[100];	//mang chua gia tri tung phan tu cua vecto
};

void InputVec(Vector&, int);	//Ham nhap vector
void OutputVec(Vector);	//Ham xuat vector
Vector AddVector(Vector, Vector);	//Ham cong 2 vector a va b, tra ve vecto tong
Vector MultiplyVector(Vector, float);	//Ham nhan vector a voi so thuc alpha, tra ve vector ket qua
Vector SubVector(Vector, Vector);//Ham tru hai vector.
Vector DivideVector(Vector, float);//chia vector cho mot so.
void AssignVector(Vector &a, Vector b);//Ham sao chep vector b cho vector a
void PrintVector(Vector a);//Ham in ra nghiem cua he phuong trinh.
