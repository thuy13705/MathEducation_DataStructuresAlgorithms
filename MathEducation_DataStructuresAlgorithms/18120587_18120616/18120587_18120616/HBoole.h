#pragma once
#include<iostream>
#include<math.h>
#include<string>

using namespace std;

struct ArrDec {
	int dec[16];	//mang so nguyen chua cac thanh phan dang thap phan cua 1 Boole
	int n;			//so luong phan tu trong mang
};
struct Boole {
	string bin;		//chuoi nhi phan cua 1 Boole
	ArrDec arrDec;	//chua thong tin ve cac so thap phan cua Boole
	string note;	//de danh dau Boole da duoc dung roi hay chua
};
struct BooleArray {
	Boole arrBoole[50];	//Mang Boole
	int len;			//so luong Boole
};
void CreateArrDec(ArrDec& a);	//khoi tao ArrDec
void CreateBoole(Boole& a);	//khoi tao Boole
void CreateBooleArray(BooleArray& a);	//khoi tao BooleArray
ArrDec GanArrDec(const ArrDec); //Ham gan struct Arrdec vao mot ArrDec khac
Boole GanBoole(const Boole);	//Ham gan struct Boole vao 1 Boole khac
BooleArray GanBooleArray(const BooleArray);	//Ham gan struct BooleArray vao 1 BooleArray khac
void InputString(string& s);	//Ham nhap chuoi da thuc cua ham boole
void StandardString(string &s);	//ham chuan hoa chuoi duoc nhap vao (xoa khoang trang, xoa dau '+' du)
int IsBoole(string s);	//ham kiem tra chuoi nhap vao dung ko, return -1:khong thoa, return countAdd (so bieu thuc ham boole):thoa
string* StandardBoole(string s, int n);	//Ham chuyen chuoi chu cai thanh chuoi bit
int Pow(int x, int y);	//tinh x^y
int BinaryStringToDec(const string str);	//chuyen tu chuoi binary sang so thap phan
string SortString(string);	//ham sap xep thu tu cac ki tu trong chuoi, va chuyen ve dang 1,0,-
bool IsMatch(const string a, const string b);	//Kiem tra 2 chuoi a va b co noi voi nhau duoc khong
bool IsMatchArray(const BooleArray arr);	//Kiem tra cac phan tu Boole trong mang BooleArray co the noi voi nhau khong
Boole Match(Boole& a, Boole& b);	//Ham noi 2 Boole a va b, tra ve 1 Boole
ArrDec InsertArr(const ArrDec a, const ArrDec b);	//Ham noi 2 ArrDec a va b tra ve ArrDec 
void SortArray(ArrDec& a);	//Ham sap xep mang ArrDec
bool IsSameBoole(const Boole, const Boole);	//Kiem tra 2 Boole co giong nhau khong
void MatchArray(BooleArray& arr); //Ham noi cac Boole co the noi trong BooleArray
string BinToString(const Boole);	//Ham chuyen tu chuoi bit sang da thuc
bool IsSameBit(const string bit, const string s);	//Kiem tra chuoi bit co giong voi chuoi s khong
void InputBooleArray(BooleArray& a);	//Ham nhap du lieu vao BooleArray a
bool IsArrDecInArrDec(const ArrDec smaller, const ArrDec bigger);	//kiem tra mang smaller co thuoc mang bigger
string* UndefinePrime(BooleArray&, const ArrDec, int&);//Ham tra ve cac bieu thuc con thieu, chua xac dinh duoc, countPrime: so luong bieu thuc; underfineBoole: mang Boole chua cac boole chua xac dinh; b: mang chua cac so chua duoc cover
void FinalBoole(BooleArray&);	//Ham in ra cac da thuc toi tieu cua ham boole tu mang Boole arrB
