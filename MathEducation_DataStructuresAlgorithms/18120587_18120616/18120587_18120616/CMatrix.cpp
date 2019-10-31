
#include "HMatrix.h"



//------------Cai dat cac phuong thuc khoi tao.-------------------------
//Ham khoi tao mac dinh.
Matrix::Matrix()
{
	//Khoi tao ma tran rong.
	m = 0; n = 0;
	a = NULL;
}

//Ham khoi tao ma tran voi so dong so cot cho san.
Matrix::Matrix(const Matrix &b)
{
	//Gan so dong, cot cho ma tran.
	m = b.m;
	n = b.n;
	//Cap phat vung nho cho mang.
	a = new float*[m];
	for (int i = 0; i < m; i++)
		a[i] = new float[n];
	//Gan tung phan tu cua ma tran b voi ma tran.
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = b.a[i][j];
}

//Ham khoi tao ma tran voi so dong so cot cho san.
Matrix::Matrix(int sd, int sc)
{
	//Gan so dong so cot.
	m = sd;
	n = sc;
	//Cap phat bo nho cho mang.
	a = new float*[m];
	for (int i = 0; i < m; i++)
		a[i] = new float[n];
	//Gan gia tri mac dinh la 0 cho tung phan tu.
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
}


//------------Cai dat cac getter/setter.--------------------------------
int Matrix::M()
{
	return m;
}
int Matrix::N()
{
	return n;
}
void Matrix::getM(int value)
{
	m = value;
}
void Matrix::getN(int value)
{
	n = value;
}


//-----------Cai dat phuong thuc huy -----------------------------------
Matrix::~Matrix()
{
	//Giai phong bo nho khi khong su dung.
	for (int i = 0; i < m; i++)
		delete[] a[i];
	delete[]a;
}


//-----------Kiem tra co phai la ma tran vuong khong.-------------------
// 1: ma tran vuong
// 0: khong phai ma tran vuong.
int Matrix::checkSquareMatrix()
{
	if (m != n)
		return 0;
	else
		return 1;
}


//-----------Cai dat ham nhap xuat--------------------------------------
//Nhap ma tran.
void Matrix::GetArray()
{
	//Nhap so dong, so cot cua ma tran.
	do
	{
		cout << "Nhap so dong:";
		cin >> m;
		cout << "Nhap so cot:";
		cin >> n;
	} while (m <= 0 || n <= 0);
	//Cap phat bo nho cho mang.
	a = new float*[m];
	for (int i = 0; i < m; i++)
		a[i] = new float[n];
	//srand(time(NULL));
	//Nhap tung phan tu cua ma tran.
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];// = rand() % (100 + 1);
		}
}

//In ma tran vua nhap.
void Matrix::PrintArray()
{
	for (int i = 0; i < m; i++)//Duyet theo dong.
	{
		for (int j = 0; j < n; j++)//Duyet theo cot.
			cout << a[i][j] << "\t";//In tung phan tu trong mang.
		cout << endl;
	}
}


//------------Ham gan voi mot ma tran cho truoc.------------------------
Matrix &Matrix::operator=(const Matrix &b)
{
	//Kiem tra xem vung nho can gan co trung khong.
	//Trung thi tra ve ma tran ban dau.
	if (this == &b)
		return *this;
	else
	{
		//Xoa vung nho cua a.
		for (int i = 0; i < m; i++)
			delete[]a[i];
		delete[]a;
		//Gan lai so dong so cot ma tran b cho ma tran can gan.
		m = b.m;
		n = b.n;
		//Cap phat lai bo nho cho ma tran.
		a = new float*[m];
		for (int i = 0; i < m; i++)
			a[i] = new float[n];
		//Gan ma tran b cho ma tran can gan.
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = b.a[i][j];
		return *this; //Tra ve ma tran can gan.
	}

}


//--------------Tim ma tran bac thang.----------------------------------
Matrix &Matrix::EchelonMatrix()
{
	int i = 0, j = 0;//Gan gia tri bat dau.
	while (i < m && j < n)//Dieu kien dung.
	{
		//Kiem tra phan tu dau dong.
		if (a[i][j] != 0)
		{
			//Bien doi ma tran dk-a[k][j]/a[i][j]di.
			//Doi cac dong k>i.
			for (int k = i + 1; k < m; k++)
			{
				int temp = a[k][j];
				for (int l = j; l < n; l++)
				{
					a[k][l] = a[k][l] * a[i][j] - temp * a[i][l];
				}
			}
			//Tang gia tri i, j;
			i++;
			j++;
		}
		else
		{
			//Tim dong co phan tu khac 0 tai cot j.
			int k = i + 1;
			while (k < m && a[i][j] == 0)
			{
				k++;
			}
			//Neu k==m thi khong co phan tu khac 0 o cot j nen tang j sang cot tiep theo.
			if (k == m) j++;
			else
			{
				//Neu tim duoc dong co phan tu khac 0 thi doi dong i voi dong tim duoc.
				for (int ni = j; ni < n; ni++)
					swap(a[k][ni], a[i][ni]);
			}
		}
	}
	//Tra ve ma tran bac thang.
	return *this;
}


//-----------Tim dinh thuc ma tran.-------------------------------------
//Chuyen ma tran ve bac thang roi tinh theo duong cheo chinh.
float Matrix::DetMatrix()
{
	float det = 1;//KHoi tao det=1 de thuc hien nhan.
	//Chuyen doi ve ma tran bac thang.
	int i = 0, j = 0;//Khoi tao gia tra dau tien
	while (i < m && j < n)//Dieu kien dung vong lap.
	{
		if (a[i][j] != 0)
		{
			for (int k = i + 1; k < m; k++)
			{
				det *= 1 / a[i][j];//Nhan voi gia tri bien doi.
				int temp = a[k][j];//luu gia tri de khong bi mat khi chuyen doi ma tran.
				for (int l = j; l < n; l++)
				{
					a[k][l] = a[k][l] * a[i][j] - temp * a[i][l];

				}
			}
			i++;
			j++;
		}
		else
		{
			int k = i + 1;
			while (k < m && a[k][j] == 0)
			{
				k++;
			}
			if (k == m) j++;
			else
			{
				for (int ni = j; ni < n; ni++)
					swap(a[k][ni], a[i][ni]);
				det = -det;//Khi thuc hien doi hai dong thi det se doi dau.
			}
		}
	}
	//Tinh dinh thuc bang cach nhan duong cheo chinh.
	for (int i = 0; i < n; i++)
		det *= a[i][i];
	return det;//Tra ve gia tri dinh thuc.
}


//-----------Ma tran nghich dao.----------------------------------------
//Dua tren ma tran phu hop.
Matrix Matrix::InverseMatrix()
{
	//Gan de khong lam thay doi ma tran.
	Matrix temp = *this;
	//Tim dinh thuc cua ma tran.
	float detA = temp.DetMatrix();
	if (detA == 0)
		cout << "Khong ton tai ma tran nghich dao!!!";
	else
	{
		Matrix c(m, n);//Ma tran ket qua.
		Matrix b(m - 1, n - 1);//Ma tran con sau khi bo di dong i, cot j.
		for (int i = 0; i < n; i++)//Duyet tung dong.
			for (int j = 0; j < n; j++)//Duyet phan tu tren dong.
			{
				int nl = 0;//Khoi tao gia tri dong ban dau cho ma tran ket qua.
				//Tim ma tran con.
				for (int l = 0; l < n; l++)//Duyet dong de tim ma tran con.
				{
					int nk = 0, k = 0;//nk: gan cot cua ma tran ket qua ban dau bang 0.
					//k: cot bat dau duyet tim ma tran con.
					while (k < n)//Dieu kien dung cua k.
					{
						//Khi k=j hoac l=i thi bo qua dong do.
						//Tang k len de kiem tra xem da het cot chua.
						if (k == j || l == i) k++;//
						else
						{
							//Gan phan tu cho ma tran con.
							b.a[nl][nk] = a[l][k];
							nk++;//Tang cot cua ma tran ket qua.
							k++;//tang cot cua ma tran tran dang xet.
						}
					}
					if (l != i) nl++;//tang dong cua ma tran con.
				}
				//Tim tung phan tu trong ma tran phu hop.
				c.a[j][i] = pow(-1, i + j)*b.DetMatrix() / detA;
				if (c.a[j][i] == -0)
					c.a[j][i] = 0;
			}
		return c;//Tra ve mang tran nghich dao.
	}
}


//------------Nhan hai ma tran.-----------------------------------------
Matrix Matrix::MultiplyMatrix(const Matrix &b)
{
	//Khoi tao ma tran luu giu ket qua.
	Matrix c(m, b.n);
	for (int i = 0; i < m; i++)//Duyet tung dong trong phan tu moi.
		for (int j = 0; j < b.n; j++)//Duyet tung cot.
			for (int k = 0; k < n; k++)//Duyet so luong phan tu tren dong i, cot j.
				//Gia tri tai vi tri can tinh bang tong tung phan tu tren hang nhan voi cot kia.
				c.a[i][j] += a[i][k] * b.a[k][j];
	return c;//Tra ve ma tran can tinh.
}


//------------Hang ma tran.---------------------------------------------
int Matrix::RankMatrix()
{
	Matrix c;
	c = this->EchelonMatrix();//Gan mang de khong lam thay doi cac gia tri trong mang.

	int count = 0;//Bien de tinh hang ma tran.
	for (int i = 0; i < m; i++)//Duyet tung dong.
	{
		//Kiem tra dong nao khac 0.
		bool t = false;//Gan cho dong do deu bang 0.
		for (int j = 0; j < n; j++)//duyet tung phan tu tren dong.
			//Neu co gia tri khac 0 se gan t=true.
			if (c.a[i][j] != 0)
				t = true;
		//Neu khac 0 thi tang bien dem count.
		if (t == true)
			count++;
	}
	return count;//Tra ve hang  cua ma tran.
}


//----------Giai he phuong trinh tuyen tinh.----------------------------
//-1: He pt vo nghiem.
// 0: He pt co nghiem duy nhat.
// 1: He co vo so nghiem.
int Matrix::SolveLinearEquationMatrix()
{
	Matrix b(m, n - 1);//Ma tran de luu gia tri mang con.
	//Sao chep phan tu vao mang con.
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n - 1; j++)
			b.a[i][j] = a[i][j];
	//Tim hang ma tran A.
	int rankB = b.RankMatrix();
	//Tim hang ma tran A|B
	int rankA = this->RankMatrix();
	cout << endl;
	this->PrintArray();
	cout << endl;
	//Kiem tra dieu kien he phuong trinh vo nghiem.
	if (rankA == rankB + 1)
		return -1;
	//Kiem tra dieu kien he phuong trinh co nghiem duy nhat.
	if (rankB == rankA)
		if (rankB == n - 1)
		{

			Matrix temp(1, n - 1);//Khoi tao ma tran ket qua.
			for (int i = rankA - 1; i >= 0; i--)
			{
				//Giai he phuong trinh.
				float t = a[i][n - 1];
				for (int k = n - 2; k > i; k--)
					t -= a[i][k] * temp.a[0][k];
				temp.a[0][i] = t / a[i][i];//tinh nghiem gan vao ma tran ket qua.
			}
			cout << "\nNghiem cua he: ";
			temp.PrintArray();//In ra nghiem cua he phuong trinh.
			cout << endl;
			return 0;
		}
		else
			//he phuong trinh co co so nghiem.
			if (rankB < n - 1)
			{
				/*int an = n - rankB - 1;//so an cua he phuong trinh.
				Vector aV;
				aV.n = an + 1;
				//Gan nghiem bang 0;
				//at1+bt2+..+ctan+d
				for (int i = 0; i <= an; i++)
					aV.vec[i] = 0;
				Vector *temp = new Vector[n - 1];//Khoi tao bo nghiem cua he phuong trinh.
				//Gan gia tri cho cac nghiem cua he phuong trinh
				for (int i = 0; i < n - 1; i++)
				{
					temp[i].n = an + 1;
					AssignVector(temp[i], aV);
				}
				//neu dong nao bang 0 thi gan gia tri cua i bang t va in ra nghiem.
				for (int i = n - 2; i > n - 2 - an; i--)
				{
					temp[i].vec[n - 2 - i + 1] = 1;
					cout << "x" << i + 1 << " = :";
					cout << temp[i].vec[0];

					//In ra nghiem
					for (int j = 1; j < temp[i].n; j++)
						if (temp[i].vec[j] != 0)
							cout << " + " << temp[i].vec[j] << "t" << j;
					cout << endl;
				}
				//tim nghiem cua nhung dong khac 0
				for (int i = rankA - 1; i >= 0; i--)
				{
					//chuyen gia tri trong he thanh vector
					Vector t;
					t.n = aV.n;
					AssignVector(t, aV);
					t.vec[0] = a[i][n - 1];
					for (int k = n - 2; k > i; k--)
						t = SubVector(t, MultiplyVector(temp[k], a[i][k]));
					temp[i] = DivideVector(t, a[i][i]);//tinh nghiem gan vao ma tran ket qua.
					//cout << endl;
					//in ra nghiem.
					if (temp[i].vec[0] != 0)
					{
						cout << "x" << i + 1 << " = :";
						cout << temp[i].vec[0];
					}
					for (int j = 1; j < temp[i].n; j++)
						if (temp[i].vec[j] != 0)
							cout << " + " << temp[i].vec[j] << "t" << j;
					cout << endl;
				}
				cout << endl;*/
				return 1;
			}

}