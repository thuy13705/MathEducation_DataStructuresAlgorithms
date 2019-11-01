#include"HVector.h"

using namespace std;

//Ham nhap vector a voi len la so luong phan tu cua vecto a
void InputVec(Vector& a, int len) {
	a.n = len;		//gan so luong phan tu cua vector a = len
	cout << "Nhap Vector:" << endl;		//thong bao nhap
	for (int i = 0; i < a.n; i++) {		//duyet cac phan tu cua vector a
		cout << "\tvec[" << i + 1 << "]= ";		//thong bao nhap tung gia tri
		cin >> a.vec[i];	//nhap gia tri
	}
}

//Ham xuat vector a ra man hinh
void OutputVec(Vector a) {
	cout << "Vector: (";		//xuat thong bao
	for (int i = 0; i < a.n - 1; i++) {		//duyet vong lap tu phan tu dau den phan tu thu n-2
		cout << a.vec[i] << ", ";		//xuat gia tri cua phan tu dau den phan tu thu n-2 cua vector
	}
	cout << a.vec[a.n - 1] << ")" << endl;		//xuat gia tri phan tu cuoi cua vector
}

//Ham cong 2 vector a va b, tra ve vecto tong
Vector AddVector(Vector a, Vector b) {
	Vector sum;			//tao bien Vector sum de chua ket qua
	sum.n = a.n;		//gan so luong phan tu cua vector a cho vector sum
	for (int i = 0; i < a.n; i++) {		//duyet vong lap cac phan tu cua vector
		sum.vec[i] = a.vec[i] + b.vec[i];		//gia tri tung phan tu cua sum bang tong cua phan tu tuong ung cua vector a va b
	}
	return sum;			//tra ve ket qua la Vector sum da duoc tinh
}

//Ham nhan vector a voi so thuc alpha, tra ve vector ket qua
Vector MultiplyVector(Vector a, float alpha) {
	Vector ans;		//tao bien Vector ans de chua ket qua
	ans.n = a.n;		//gan so luong phan tu cua vector a cho vector ans
	for (int i = 0; i < a.n; i++) {		//duyet vong lap cac phan tu cua vector
		ans.vec[i] = a.vec[i] * alpha;		//gia tri tung phan tu cua ans bang tich cua phan tu tuong ung cua vector a*alpha
	}
	return ans;		//tra ve ket qua la Vector ans da duoc tinh
}

//Ham tru hai vector.
Vector SubVector(Vector a, Vector b)
{
	Vector sub;			//tao bien Vector sum de chua ket qua
	sub.n = a.n;		//gan so luong phan tu cua vector a cho vector sub
	for (int i = 0; i < a.n; i++) {		//duyet vong lap cac phan tu cua vector
		sub.vec[i] = a.vec[i] - b.vec[i];		//gia tri tung phan tu cua sub bang hieu cua phan tu tuong ung cua vector a va b
	}
	return sub;
}

//chia vector cho mot so.
Vector DivideVector(Vector a, float alpha)
{
	Vector ans;		//tao bien Vector ans de chua ket qua
	ans.n = a.n;		//gan so luong phan tu cua vector a cho vector ans
	for (int i = 0; i < a.n; i++) {		//duyet vong lap cac phan tu cua vector
		ans.vec[i] = a.vec[i] / alpha;		//gia tri tung phan tu cua ans bang tich cua phan tu tuong ung cua vector a*alpha
	}
	return ans;
}

//Gan vector b cho vector a.
void AssignVector(Vector &a, Vector b)
{
	for (int i = 0; i < a.n; i++)
		a.vec[i] = b.vec[i];
}

//Ham in ra nghiem cua he phuong trinh.
void PrintVector(Vector a)
{
	cout << a.vec[0];
	for (int j = 1; j < a.n; j++)
		if (a.vec[j] != 0)
			cout << " + " << a.vec[j] << "t" << j;
}