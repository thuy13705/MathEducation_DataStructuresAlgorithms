#include"HBoole.h"

using namespace std;

//khoi tao ArrDec a
void CreateArrDec(ArrDec& a) {
	a.n = 0;
	for (int i = 0; i < 16; i++) {
		a.dec[i] = -1;
	}
}
//khoi tao Boole a
void CreateBoole(Boole& a) {
	a.bin = "    ";
	CreateArrDec(a.arrDec);
	a.note = "";
}
//khoi tao BooleArray a
void CreateBooleArray(BooleArray& a) {
	a.len = 0;
	for (int i = 0; i < 50; i++) {
		CreateBoole(a.arrBoole[i]);
	}
}
//Ham gan struct Arrdec (a) vao mot ArrDec khac
ArrDec GanArrDec(const ArrDec a) {
	ArrDec ans;
	ans.n = a.n;
	for (int i = 0; i < a.n; i++) {
		ans.dec[i] = a.dec[i];
	}
	return ans;
}
//Ham gan struct Boole (a) vao 1 Boole khac
Boole GanBoole(const Boole a) {
	Boole ans;
	ans.bin = a.bin;
	ans.note = a.note;
	ans.arrDec = GanArrDec(a.arrDec);
	return ans;
}
//Ham gan struct BooleArray (a) vao 1 BooleArray khac
BooleArray GanBooleArray(const BooleArray a) {
	BooleArray ans;
	ans.len = a.len;
	for (int i = 0; i < 50; i++) {
		ans.arrBoole[i] = GanBoole(a.arrBoole[i]);
	}
	return ans;
}
//ham chuan hoa chuoi s duoc nhap vao (xoa khoang trang, xoa dau '+' du)
void StandardString(string& s) {
	int i = 0;
	while (i < s.length()) {//duyet chuoi s, neu s[i] la khoang cach, thi xoa s[i]
		if (s[i] == ' ')
			s.erase(i, 1);
		else i++;
	}
	while (s[0] == '+') s.erase(0, 1);	//xoa dau '+' tai vi tri dau chuoi
	while (s[s.length() - 1] == '+') s.erase(s.length() - 1, 1);	//xoa dau '+' tai vi tri cuoi chuoi
	i = 0;	//set lai i
	while (i < s.length()) {
		if (s[i] == '+' && s[i + 1] == '+') s.erase(i, 1);	//neu co 2 dau '+' ke nhau -> xoa 1 dau '+'
		else i++;
	}
}
//Ham nhap chuoi s - da thuc cua ham boole
void InputString(string& s) {
	int i;
	cout << "Nhap ham boole (cac ki tu a b c d, '+' de phan cach bieu thuc, in hoa de KHANG DINH, viet thuong de phu dinh):\n";
	cin.ignore();
	getline(cin, s);
	StandardString(s);	//chuan hoa chuoi, xoa het cac khoang cach, dau '+' du
}
//ham sap xep thu tu cac ki tu trong chuoi s, va chuyen ve dang 1,0,-
string SortString(string s) {
	int i = 0;
	string ans = "    ";	//(string) ans chua ket qua tra, khoi tao la chuoi chua 4 khoang trang (tuong ung voi 4 bien)
	for (i = 0; i < s.length(); i++) {
		if (s[i] == 'a') ans[0] = '0';
		if (s[i] == 'b') ans[1] = '0';
		if (s[i] == 'c') ans[2] = '0';
		if (s[i] == 'd') ans[3] = '0';
		if (s[i] == 'A') ans[0] = '1';
		if (s[i] == 'B') ans[1] = '1';
		if (s[i] == 'C') ans[2] = '1';
		if (s[i] == 'D') ans[3] = '1';
	}
	for (i = 0; i < 4; i++) {
		if (ans[i] == ' ') ans[i] = '-';	//neu vi tri nao khong co (a[i]= khoang cach) -> a[i]='-'
	}
	return ans;
}
//Ham chuyen chuoi chu cai (s) thanh cac chuoi bit, n la so da thuc trong chuoi s
string* StandardBoole(string s, int n) {
	int i = 0, index = 0, j;
	string temp;
	string* ble = new string[n];	//tao (string*)ble chua ket qua tra ve

	while (i < s.length()) {	//duyet chuoi s
		j = 0;
		temp = "    ";	//khoi tao bien temp = chuoi chua 4 khoang cach
		while (s[i] != '+' && s[i] != NULL) {	//trong khi s[i] != '+' va != NULL, ta luu s[i] vao temp (phan tach tung bieu thuc trong s)
			temp[j] = s[i];
			j++;
			i++;
		}
		ble[index] = SortString(temp);	//sap xep lai thu tu bien trong temp, dua chung ve dang 1,0,- roi luu vao ble[index]
		i++;
		index++;
	}
	return ble;
}
//ham kiem tra chuoi s nhap vao dung ko, return -1:khong thoa, return countAdd (so bieu thuc ham boole):thoa
int IsBoole(string s) {
	int countAdd = 1;
	if (s == "") return -1;
	for (int i = 0; i < s.length(); i++) {	//Duyet het chuoi s, neu co ki tu khac cac ki tu cho phep (a, b, c, d, A, B, C, D, +) return -1
		if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c' && s[i] != 'd' && s[i] != '+'
			&& s[i] != 'A' && s[i] != 'B' && s[i] != 'C' && s[i] != 'D')
			return -1;
		if (s[i] == '+') countAdd++;	//cac da thuc cach nhau boi dau +, dem so dau cong de dem so bieu thuc
	}
	return countAdd;	//neu chuoi s dung - return so bieu thuc ham bool
}
//tinh x^y
int Pow(int x, int y) {
	if (y == 0) return 1;
	int ans = 1;
	for (int i = 0; i < y; i++) ans *= x;
	return ans;
}
//Ham chuyen tu chuoi bit str sang dang thap phan
int BinaryStringToDec(const string str) {
	int i, ans = 0;
	for (i = 0; i < 4; i++)
		ans += (str[i] - '0') *Pow(2, 3 - i);
	return ans;
}
//Sap xep mang so nguyen cua ArrDec a
void SortArray(ArrDec& a) {
	int i, j, x;
	for (i = 0; i < a.n; i++)
		for (j = i; j < a.n; j++) {
			if (a.dec[i] > a.dec[j]) {
				x = a.dec[i];
				a.dec[i] = a.dec[j];
				a.dec[j] = x;
			}
		}
}
//Ham noi 2 ArrDec a va b tra ve ArrDec 
ArrDec InsertArr(const ArrDec a, const ArrDec b) {
	ArrDec ans;
	CreateArrDec(ans);	//Khoi tao (ArrDec)ans chua ket qua duoc tra ve
	ans.n = a.n + b.n;
	for (int i = 0; i < a.n; i++) {		//duyet cac phan tu trong a, gan vao ans voi chi so tuong ung
		ans.dec[i] = a.dec[i];
	}
	for (int i = a.n; i < (b.n + a.n); i++) {	//duyet cac phan tu trong b, va gan noi tiep vao ans
		ans.dec[i] = b.dec[i - a.n];
	}
	SortArray(ans);	//sap xep lai thu tu cac so trong ans
	int i = 0;
	int j;
	while (i < ans.n) {	//xoa het cac phan tu trung trong ans
		if (ans.dec[i] == ans.dec[i + 1]) {		//neu 2 phan tu lien ke nhau bang nhau thi xoa di 1 phan tu
			for (j = i; j < ans.n; j++) {
				ans.dec[j] = ans.dec[j + 1];

			}
			ans.dec[j] = -1;
			ans.n--;
		}
		else i++;
	}
	return ans;
}
//Kiem tra 2 chuoi bit a va b co noi voi nhau duoc khong (neu chi khac nhau 1 vi tri thi noi duoc)
bool IsMatch(const string a, const string b) {
	int i, count = 0;	//bien (int)count dung de dem so vi tri khac hau cua a va b
	if (a == b) return false;	//bien a=b thi khong the noi
	for (i = 0; i < 4; i++) {	//duyet chuoi bit, tai tung vi tri i, neu khac nhau -> count += 1
		if (a[i] != b[i]) count++;
	}
	if (count == 1) return true;	//neu chi khac nhau 1 vi tri -> true
	return false; //cac truong hop con lai return false
}
//Kiem tra cac phan tu Boole trong mang BooleArray (arr) co the noi voi nhau khong
bool IsMatchArray(const BooleArray arr) {
	int i, j;
	for (i = 0; i < arr.len; i++) //duyet tung phan tu trong arr
		for (j = i + 1; j < arr.len; j++) { //so sanh arr[i] voi cac phan tu con lai, neu co the noi voi nhau -> return true
			if (IsMatch(arr.arrBoole[i].bin, arr.arrBoole[j].bin)) return true;
		}
	return false; //truong hop khong co cap phan tu nao trong arr co the noi voi nhau -> return false
}
//Ham noi 2 Boole a va b, tra ve 1 Boole
Boole Match(Boole &a, Boole &b) {
	int i;
	Boole ans;
	CreateBoole(ans);	//khoi tao bien (Boole) ans luu ket qua tra ve
	for (i = 0; i < 4; i++) {		//duyet het chuoi bin gom 4 ki tu
		if (a.bin[i] != b.bin[i]) {	//neu a.bin[i] != b.bin[i] thi ans.bin[i]='-'
			ans.bin[i] = '-';
		}
		else ans.bin[i] = a.bin[i];	//neu a.bin[i]=b.bin[i] thi ans.bin[i]=a.bin[i]=b.bin[i]
	}
	a.note.append("*");	//Danh dau a da duoc dung
	b.note.append("*");	//Danh dau b da duoc dung
	ans.arrDec = InsertArr(a.arrDec, b.arrDec);	//Cap nhat lai mang ans.arrDec (a.arrDec + b.arrDec)
	return ans;
}
//Kiem tra 2 Boole a va b co giong nhau khong
bool IsSameBoole(const Boole a, const Boole b) {
	int i;
	for (i = 0; i < 4; i++)
		if (a.bin[i] != b.bin[i]) return false;	//Duyet chuoi bit cua a va b, neu khac nhau tai vi tri nao -> return false
	return true;	//chuoi bin cua chung giong nhau -> return true
}
//Ham noi cac Boole co the noi trong BooleArray(arr) cho den khi cac Boole trong arr khong the noi voi nhau duoc
void MatchArray(BooleArray& arr) {
	if (!IsMatchArray(arr)) return;	//Neu trong arr khong con boole nao co the noi voi nhau thi dung lai (dieu kien dung)

	BooleArray temp;
	CreateBooleArray(temp);	//khoi tao (BooleArray)temp (bien tam chua ket qua)
	int i, j, x = 0, index;

	for (i = 0; i < arr.len; i++)	//Duyet cac Boole trong arr
		for (j = i + 1; j < arr.len; j++) {
			if (IsMatch(arr.arrBoole[i].bin, arr.arrBoole[j].bin)) {	//neu cap nao co the noi duoc thi thuc hien noi
				temp.arrBoole[x] = Match(arr.arrBoole[i], arr.arrBoole[j]);	//luu gia tri vua duoc noi vao phan tu tiep theo cua bien tam temp.arrBoole[x], danh dau cac phan tu da duoc noi
				x++;	//tang chi so cua temp.arrBoole[x]
				for (index = 0; index < x - 1; index++) {	//kiem tra xem temp.arrBoole[x] da xuat hien trong mang temp.arrBoole chua
					if (IsSameBoole(temp.arrBoole[x - 1], temp.arrBoole[index])) {//neu da xuat hien, giam chi so x
						x--;
						break;
					}
				}
			}
		}
	//lay them cac phan tu chua duoc noi
	for (i = 0; i < arr.len; i++) {
		if (arr.arrBoole[i].note == "") {
			temp.arrBoole[x] = GanBoole(arr.arrBoole[i]);
			x++;
		}
	}
	temp.len = x;
	arr = GanBooleArray(temp);
	MatchArray(arr);	//lap lai qua trinh noi cac phan tu
}
//Ham chuyen tu chuoi bin trong Boole a sang da thuc
string BinToString(const Boole a) {
	int i;
	string s = "";
	if (a.bin[0] == '1') s.append("A");
	if (a.bin[0] == '0') s.append("a");
	if (a.bin[1] == '1') s.append("B");
	if (a.bin[1] == '0') s.append("b");
	if (a.bin[2] == '1') s.append("C");
	if (a.bin[2] == '0') s.append("c");
	if (a.bin[3] == '1') s.append("D");
	if (a.bin[3] == '0') s.append("d");
	if (a.bin[0] == '-' && a.bin[1] == '-' && a.bin[2] == '-' && a.bin[3] == '-')//truong hop a.bin="----"
		s.append("1");
	return s;
}
//Kiem tra chuoi bit co giong voi chuoi s khong (ex: 11-1 giong {1111,1101})
bool IsSameBit(const string bit, const string s) {
	for (int i = 0; i < 4; i++) {
		if ((bit[i] != '-') && (bit[i] != s[i])) return false;	//neu tai 1 vi tri khac nhau va bit[i] != '-' return false
	}
	return true;
}
//Ham nhap du lieu vao BooleArray a
void InputBooleArray(BooleArray& a) {
	//mang chuoi sample chua bit cua cac so tu 0->15
	string sample[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010","1011", "1100", "1101", "1110", "1111" };
	int i, j, n, temp = 0, nBoole, nBit, nArrBoole = 0;	//
	int arrdec[16];	//mang danh dau phan tu tuong ung da xuat hien chua
	string str;

	InputString(str);	//goi ham nhap chuoi str
	n = IsBoole(str);	//kiem tra chuoi str co thoa la chuoi Boole ko, neu thoa n= so bieu thuc trong chuoi str
	cout << endl;
	while (n == -1) {	//trong khi str khong phai chuoi Boole -> nhap lai
		cout << "Nhap sai, moi nhap lai!!!" << endl;
		InputString(str);
	}
	string* str2 = new string[n];	//tao mang chuoi str2 chua n phan tu
	str2 = StandardBoole(str, n);	//luu cac bieu thuc trong chuoi str vao mang chuoi str2

	for (i = 0; i < n; i++) {	//duyet cac phan tu trong mang chuoi str2
		for (j = 0; j < 16; j++)	//duyet cac phan tu trong mang chuoi sample[16]
			if (IsSameBit(str2[i], sample[j])) {	//so sanh str2[i] voi tung sample[j], neu chung tuong dong nhau 
				if (arrdec[BinaryStringToDec(sample[j])] != 1) {	//kiem tra bit str2[i] da xuat hien chua
					a.arrBoole[temp].bin = sample[j];	//gan bit str2[i]=sample[i] vao boole tiep theo
					a.arrBoole[temp].arrDec.dec[0] = BinaryStringToDec(sample[j]);
					a.arrBoole[temp].arrDec.n = 1;
					arrdec[BinaryStringToDec(sample[j])] = 1;	//danh dau da xuat hien
					temp++;	//tang bien dem chi so
				}
			}
	}
	a.len = temp;
}
bool IsArrDecInArrDec(const ArrDec smaller, const ArrDec bigger) {
	int i, j;
	int count = 0;
	for (i = 0; i < smaller.n; i++) {	//duyet mang (ArrDec) smaller
		for (j = 0; j < bigger.n; j++)	//duyet mang (ArrDec) bigger
			if (smaller.dec[i] == bigger.dec[j]) {	//neu co mat smaller.dec[i] trong bigger.dec thi count+1
				count++;
				break;
			}
	}
	if (count == smaller.n) return true;	//neu cac phan tu cua smaller deu co trong bigger -> return true
	return false;
}
//Ham tra ve cac bieu thuc con thieu, chua xac dinh duoc, countPrime: so luong bieu thuc; underfineBoole: mang Boole chua cac boole chua xac dinh; b: mang chua cac so chua duoc cover
string* UndefinePrime(BooleArray& undefineBoole, const ArrDec b, int& countPrime) {
	int k, temp, i = 0, j, n;
	BooleArray temp_BooleArray;
	Boole temp_Boole;
	ArrDec temp_arrDec1, temp_arrDec2;
	string* ans = new string[15];

	CreateBooleArray(temp_BooleArray);
	CreateArrDec(temp_arrDec2);
	n = undefineBoole.len;

	for (temp = 1; temp <= n; temp++) {//duyet cac tap con co 1->n phan tu cua (BooleArray)undefineBoole
		k = temp;
		int* temp_arrint = new int[k];
		int index = 0;

		for (j = 0; j < k; j++)
			temp_arrint[j] = j + 1; //khoi tao gia tri cho mang temp_arrint {1,2,3,..k}

		do {
			int count = 0;	//khoi tao bien count - bien dem chi so cua tap con
			CreateArrDec(temp_arrDec2);	//khoi tao lai bien (ArrDec)temp_arrDec2 chua cac gia tri ma tap con cover
			for (j = 0; j < k; j++) {	//tap con temp_BooleArray chua phan tu nao của undefineBoole thi noi cac arrDec cua chung vao temp_arrDec2
				temp_BooleArray.arrBoole[count] = GanBoole(undefineBoole.arrBoole[temp_arrint[j] - 1]);
				temp_arrDec1 = GanArrDec(temp_arrDec2);
				temp_arrDec2 = InsertArr(temp_BooleArray.arrBoole[count].arrDec, temp_arrDec1);
				count++;	//so phan tu trong tap con temp_BooleArray
			}

			if (IsArrDecInArrDec(b, temp_arrDec2)) {	//neu temp_arrDec2 bao phu duoc (ArrDec)b thi luu bieu thuc tuong ung vao chuoi ans[i]
				for (index = 0; index < count; index++) {
					ans[i].append(BinToString(temp_BooleArray.arrBoole[index]));
					ans[i].append("+");
				}
				if (i > 0) {
					if (IsBoole(ans[0]) > IsBoole(ans[i])) {//kiem tra neu chuoi ans[i] moi duoc nhap vao nho hon cac chuoi co san thi chi giu lai ans[i]
						ans[0] = ans[i];
						for (int x = 1; x <= i; x++) {
							ans[i].clear();
						}
						i = 0;
					}
					if (IsBoole(ans[0]) < IsBoole(ans[i])) {	//neu ans[i] lon hon cac chuoi da co trong ans thi xoa ans[i]
						ans[i].clear();
						i--;
					}
					if (IsBoole(ans[0]) == IsBoole(ans[i])) {	//neu ans[i] cung so bieu thuc voi cac chuoi da co trong ans, ta xet den do dai cua cac chuoi
						if (ans[i].length() > ans[0].length()) {
							ans[i].clear();
							i--;
						}
						if (ans[i].length() < ans[0].length()) {
							ans[0] = ans[i];
							for (int x = 1; x <= i; x++) {
								ans[i].clear();
							}
							i = 0;
						}
					}
				}
				i++;
			}
			index = k - 1;
			//sinh cac tap con theo thu tu tu dien
			while ((index >= 0) && (temp_arrint[index] == n - k + index + 1))
				index--;

			if (index >= 0) {
				temp_arrint[index]++;
				for (j = index + 1; j < k; j++)
					temp_arrint[j] = temp_arrint[j - 1] + 1;
			}
		} while (index != -1);
		delete[] temp_arrint;
	}
	countPrime = i;
	return ans;

}
//Ham in ra cac da thuc toi tieu cua ham boole tu mang Boole arrB
void FinalBoole(BooleArray&arrB) {
	int countAppear[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//tao mang dem su xuat hien cua tung phan tu, khoi tao voi tung gia tri =0
	int i, j, temp;

	//for (i = 0; i < arrB.len; i++) n += arrB.arrBoole[i].arrDec.n;//tong cac phan tu cua cac mang arrDec
	for (i = 0; i < arrB.len; i++) {//Duyet cac phan tu cua BooleArray 
		for (j = 0; j < arrB.arrBoole[i].arrDec.n; j++) {	//Duyet cac phan tu trong mang arrDec cua tung arrBoole[i]
			countAppear[arrB.arrBoole[i].arrDec.dec[j]]++;	//so nao trong mang xuat hien se tang chi so tuong ung cua mang countAppear+1
		}
	}
	string mustHave;//khoi tao chuoi rong mustHave chua cac bieu thuc phai co cua da thuc toi tieu
	ArrDec arrDec1;

	CreateArrDec(arrDec1);//khoi tao bien arrDec1
	for (i = 0; i < 16; i++) {	//duyet mang countAppear
		if (countAppear[i] == 1) {	//neu so nao chi xuat hien 1 lan thi arrDec co chua no se duoc lay
			for (j = 0; j < arrB.len; j++) {	//duyet het cac boole trong (BooleArray) arrB
				for (temp = 0; temp < arrB.arrBoole[j].arrDec.n; temp++) {	// duyet het cac phan tu cua arrDec trong tung arrB[temp]
					if (arrB.arrBoole[j].arrDec.dec[temp] == i && arrB.arrBoole[j].note != "*") {//kiem tra xem phan tu co xuat hien 1 lan va co bi danh dau chua
						mustHave.append(BinToString(arrB.arrBoole[j]));	//noi da thuc cua boole vao chuoi mustHave
						mustHave.append("+");	//phan tach giua cac bieu thuc
						arrB.arrBoole[j].note = "*";	//danh dau da lay roi
					}
				}
			}
		}
	}

	int count = 0;
	ArrDec a;
	BooleArray arrBoole;

	CreateArrDec(a);
	CreateBooleArray(arrBoole);

	for (i = 0; i < arrB.len; i++) {	//Duyet het cac phan tu arrB[i] trong (BooleArray)arrB
		if (arrB.arrBoole[i].note == "*")	//Kiem tra phan tu arrB[i] da bi danh dau chua, neu roi thi cac thanh phan cua arrB[i] da duoc cover -> su xuat hien cua chung =0
			for (j = 0; j < arrB.arrBoole[i].arrDec.n; j++) {	//Duyet het phan tu trong arrDec cua arrB[i]
				countAppear[arrB.arrBoole[i].arrDec.dec[j]] = 0;	//so lan xuat hien cua tung arrDec[j]=0
			}
		else {	//neu thanh phan nao chua duoc cover
			arrBoole.arrBoole[count] = GanBoole(arrB.arrBoole[i]);	//Gan arrB[i] cho vao (BooleArray)arrBoole
			count++;//so phan tu cua arrBoole+1
		}
	}
	for (i = 0; i < 16; i++)	//duyet cac phan tu trong mang countAppear
		if (countAppear[i] != 0) {	//phan tu nao chua duoc cover duoc luu vao (ArrDec)a
			a.dec[a.n] = i;
			a.n++;
		}
	arrBoole.len = count;
	//xuat cac da thuc toi tieu 
	cout << "Cac da thuc toi tieu co the:\n";
	if (a.n == 0) {	//neu khong co
		mustHave.erase(mustHave.length() - 1, 1);
		cout << "\t(1) " << mustHave << endl;
	}
	else {
		int countPrime = 0;
		string* undefine = new string[15];
		undefine = UndefinePrime(arrBoole, a, countPrime);
		for (int i = 0; i < countPrime; i++) {
			undefine[i].erase(undefine[i].length() - 1, 1);
			cout << "\t(" << i + 1 << ") " << mustHave << undefine[i] << endl;
		}
	}
}
