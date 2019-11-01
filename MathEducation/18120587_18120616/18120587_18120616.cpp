// 18120587_18120616.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include"HBoole.h"
#include"HMatrix.h"
#include"HVector.h"

using namespace std;

void MainMenu();
void BooleMenu();
void VectorMenu();
void MatrixMenu();

int main()
{
	MainMenu();
	system("pause");
	return 0;
}

void BooleMenu() {

	while (1) {
		system("cls");
		cout << "*******************Bool********************" << endl;
		cout << "* 1. Tim cac cong thuc da thuc toi tieu   *" << endl;
		cout << "* 2. Menu chinh                           *" << endl;
		cout << "* 3. Thoat chuong trinh                   *" << endl;
		cout << "*******************************************" << endl;
		int option;
		BooleArray arrB;
		CreateBooleArray(arrB);

		cout << "Nhap lua chon: ";
		cin >> option;

		switch (option) {
		case 1: {
			cout << "Tim da thuc toi thieu cua ham bool:" << endl;
			InputBooleArray(arrB);
			MatchArray(arrB);
			FinalBoole(arrB);
			break;
		}
		case 2:
			MainMenu();
			break;
		case 3:
			exit(0);
		}
		system("pause");
	}
}
void VectorMenu()
{

	while (1) {
		system("cls");
		cout << "**************Vector**************" << endl;
		cout << "* 1. Tong 2 vector               *" << endl;
		cout << "* 2. Tich vector va 1 so alpha   *" << endl;
		cout << "* 3. Menu chinh                  *" << endl;
		cout << "* 4. Thoat chuong trinh          *" << endl;
		cout << "**********************************" << endl;
		int option;
		cout << "Nhap lua chon: ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Cong hai vector:" << endl;
			Vector vec1, vec2;
			int n1;

			cout << "Nhap so luong thanh phan cua 2 vecto: ";
			cin >> n1;
			system("cls");
			cout << "Cong hai vector:" << endl;
			InputVec(vec1, n1);
			InputVec(vec2, n1);
			OutputVec(AddVector(vec1, vec2));
			break;
		case 2:
			cout << "Nhan hai vector:" << endl;

			Vector a;
			float alpha;
			int n2;
			cout << "Nhap so luong thanh phan cua vector: ";
			cin >> n2;
			cout << "Nhap so thuc alpha: ";
			cin >> alpha;

			system("cls");
			cout << "Nhan hai vector:" << endl;
			InputVec(a, n2);
			cout << "alpha:" << alpha << endl;
			cout << "Ket qua: ";
			OutputVec(MultiplyVector(a, alpha));
			break;
		case 3:
			MainMenu();
			break;
		case 4:
			exit(0);
		}
		system("pause");
	}
}
void MatrixMenu()
{

	while (1)
	{
		system("cls");
		cout << "****** Dai so tuyen tinh ******" << endl;
		cout << "* 1. Dinh thuc ma tran        *" << endl;
		cout << "* 2. Nghich dao ma tran       *" << endl;
		cout << "* 3. Tich 2 ma tran           *" << endl;
		cout << "* 4. Hang ma tran             *" << endl;
		cout << "* 5. He phuong trinh          *" << endl;
		cout << "* 6. Menu chinh               *" << endl;
		cout << "* 7. Thoat chuong trinh       *" << endl;
		cout << "*******************************" << endl;
		int option;
		cout << "Nhap lua chon: ";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "Tinh dinh thuc cua ma tran: " << endl;
			Matrix A;

			cout << "Nhap ma tran: " << endl;
			A.GetArray();

			system("cls");
			cout << "Dinh thuc cua ma tran: " << endl;
			cout << "Ma tran vua nhap:" << endl;
			A.PrintArray();

			if (A.checkSquareMatrix() == 0)
				cout << "Khong ton tai dinh thuc!!!" << endl;
			else
				cout << "Dinh thuc cua ma tran vua nhap: " << A.DetMatrix() << endl;

			//A.~Matrix();
			break;
		}
		case 2:
		{
			cout << "Tim ma tran nghich dao: " << endl;
			Matrix Inver;

			cout << "Nhap ma tran: " << endl;
			Inver.GetArray();

			system("cls");
			cout << "Tim ma tran nghich dao: " << endl;
			cout << "Ma tran vua nhap:" << endl;
			Inver.PrintArray();

			if (Inver.checkSquareMatrix() == 0)
				cout << "Khong ton tai ma tran nghich dao!!!" << endl;
			else
			{
				cout << "Ma tran nghich dao: " << endl;
				Matrix temp = Inver.InverseMatrix();
				temp.PrintArray();
			}

			//Inver.~Matrix();
			break;
		}
		case 3:
		{
			cout << "Nhan hai ma tran:" << endl;

			Matrix Mt1;
			cout << "Nhap ma tran thu nhat: " << endl;
			Mt1.GetArray();

			Matrix Mt2;
			cout << "Nhap ma tran thu hai: " << endl;
			Mt2.GetArray();
			system("cls");
			cout << "Ma tran vua nhap:" << endl;
			Mt1.PrintArray();
			cout << "Ma tran vua nhap:" << endl;
			Mt2.PrintArray();

			cout << "Ket qua:" << endl;
			if (Mt1.N() != Mt2.M())
				cout << "Khong the thuc hien nhan ma tran." << endl;
			else
				Mt1.MultiplyMatrix(Mt2).PrintArray();
			//Mt1.~Matrix();
			//Mt2.~Matrix();
			break;
		}
		case 4:
		{
			cout << "Tim hang cua ma tran: " << endl;
			Matrix rank;

			cout << "Nhap ma tran : " << endl;
			rank.GetArray();

			system("cls");
			cout << "Tim hang cua ma tran: " << endl;
			cout << "Ma tran vua nhap:" << endl;
			rank.PrintArray();
			cout << "Ma tran bac thang: " << endl;
			rank.EchelonMatrix().PrintArray();
			cout << "Hang cua ma tran: " << rank.RankMatrix() << endl;
			//rank.~Matrix();
			break;
		}
		case 5:
		{
			cout << "Giai he phuong trinh tuyen tinh: " << endl;

			Matrix hpt;
			cout << "so cot phai lon hon 1." << endl;
			cout << "Nhap he phuong trinh can giai: " << endl;
			hpt.GetArray();

			system("cls");
			cout << "Giai he phuong trinh tuyen tinh: " << endl;
			cout << "He phuong trinh vua nhap :" << endl;
			hpt.PrintArray();
			int temp_hpt = hpt.SolveLinearEquationMatrix();
			cout << "Ket qua: " << endl;
			if (temp_hpt == 0)
				cout << " he phuong trinh co nghiem duy nhat." << endl;
			if (temp_hpt == -1)
				cout << "hpt vo nghiem." << endl;
			if (temp_hpt == 1)
				cout << "He co vo so nghiem." << endl;

			//hpt.~Matrix();
			break;
		}
		case 6:
		{
			MainMenu();
			break;
		}
		case 7:
			exit(0);
		}
		system("pause");
	}
}

void MainMenu()
{
	system("cls");
	cout << "***********MainMenu************" << endl;
	cout << "* 1. Ham Bool                 *" << endl;
	cout << "* 2. Vector                   *" << endl;
	cout << "* 3. Dai so tuyen tinh        *" << endl;
	cout << "* 4. Thoat chuong trinh       *" << endl;
	cout << "*******************************" << endl;
	int option;
	bool flag = true;
	while (flag)
	{
		cout << "Nhap lua chon: ";
		cin >> option;
		switch (option)
		{
		case 1:
			BooleMenu();
			break;
		case 2:
			VectorMenu();
			break;
		case 3:
			MatrixMenu();
			break;
		case 4:
			exit(0);
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
