#include "QInt.h"
// Ham` phu. tro.
int stringtoInt(string a)
{
	stringstream s(a);
	int b;
	s >> b;
	return b;
}
int QInt::count()
{
	return binary.length();
}
QInt::QInt()
{
	binary = "";
}
void QInt::checkBit(QInt &a, QInt &b) // Kie^?m tra xem 2 so^' co' du? so^' pha^`n tu? kho^ng
{
	int count = a.count() - b.count();
	if (count < 0)
	{
		for (int i = 0;i < -count;i++)
			a.binary.insert(0, "0");
	}
	else if (count > 0)
		for (int i = 0;i < count;i++)
			b.binary.insert(0, "0");
	else;
}
void QInt::eraze0() // Xoa' bit 0 thua`
{
	while(1) // 
	{
		string temp = binary.substr(0, 1);
		if (temp == "1")
			break;
		else binary.erase(0, 1);
	}
}
// Shirf left/right
QInt QInt::operator<<(int a)
{
	for (int i = 0;i < a;i++)
	{
		if (binary.length() == 128)
			binary.erase(0, 1);
		binary = binary + "0";
	}
	return *this;
}
QInt QInt::operator>>(int a)
{
	for (int i = 0;i < a;i++)
	{
		binary.erase(binary.length() - 1, 1);
	}
	return *this;
}
// +-*/
QInt QInt::operator+(QInt a) {
	int du, d, s;
	QInt c;
	checkBit(a, *this);
	int count = a.count() - 1;
	// -1 do gia' tri. length()/length() trong string la` to^?ng so^' ki' tu.
	du = 0; // So^' ca^`n nho' VD: 1 + 1 = 0 nho' 1
	string temp; // Bie^'n ta.m de? chuye^?n tu` int sang string
	for (int j = count; j >= 0; j--) {
		// Tim so^' can^` nho' sau khi co^.ng
		d = (stringtoInt(a.binary.substr(j, 1)) + stringtoInt(this->binary.substr(j, 1)) + du) / 2;
		// Gia tri sau khi co^.ng
		s = stringtoInt(a.binary.substr(j, 1)) + stringtoInt(this->binary.substr(j, 1)) + du - 2 * d;
		ostringstream os;
		os << s;
		temp = os.str();
		c.binary = c.binary.insert(0, temp); // Luu ket qua
		du = d;
	}
	if (c.count() < 128)
	{
		ostringstream os;
		os << du;
		temp = os.str();
		c.binary = c.binary.insert(0, temp);
	}
	c.eraze0();
	return c;
}
QInt QInt::operator-(QInt a)
{
	a = ~a;
	QInt c;
	c.binary = "1";
	a = a + c;
	c = a + *this;
	c.eraze0();
	return c;
}
QInt QInt::operator*(QInt a) // Du.a tre^n thua^.t toa'n trong slide
{
	int count = a.count();
	*this = *this << count;
	for (int i = count - 1;i >= 0;i--)
	{
		if (a.binary.substr(a.count() - 1, 1) == "1")
			a = *this + a;
		a = a >> 1;
	}
	return a;
}
QInt QInt::operator/(QInt a) // Du.a tre^n thua^.t toa'n trong slide
{
	QInt::eraze0();
	int count = QInt::count();
	if (binary.substr(0, 1) == "0")
		count++; 
	// De^'m ca? bit da^'u (Ne^'u bit 127 = 1 thi` no' la` so^' a^m => da~ ti'nh bit da^'u)
	QInt c;
	// Xe't bit da^'u cuo^'i cu`ng
	if (count == 128 && binary.substr(0, 1) == "1")
		c = ~c; 
	// Khoi tao bie^'n ta.m de^? bo? di pha^`n thu`a cua Q khi di.ch tra'i
	QInt d = *this; 
	int temp = 0;
	// Bien^' ta.m de? so sa'nh da^'u
	int temp1 = 0;
	// Bie^'n ta.m de? luu du~ lie^.u cho do~ pha?i go.i ha`m
	for (int i = count;i > 0;i--)
	{
		*this = *this << 1; // 1110
		temp++;
		c = c << 1; // 0000
		a = a << 1;
		if (binary.substr(temp, 1) == "1")
		{
			temp1 = c.count() - 1;
			c.binary.erase(temp1, 1);
			c.binary.insert(temp1, "1");
		}
		// Khi di.ch tra'i Q sang 1 don vi., ne^'u di.ch qua vi. tri' bit da^'u +1
		// thi` gan' qua A[0] nhu thua^.t toa'n slide
		d = d << 1;
		c = c - a; // 0000 - 0011 ~ 00000000 - 00110000
		if (c.binary.substr(127, 1) == "1")
			c = c + a; // Kho^i phu.c ne^'u A < 0
		else { 
			temp1 = QInt::count() - 1;
			binary.erase(temp1, 1);
			binary.insert(temp1, "1"); 
			// Q[0] = 1
		}
	}
	*this = *this - d;
	return *this;
}
// Operator
QInt QInt::operator~()
{
	QInt a;
	int count = 0;
	for (int i = QInt::count() - 1;i >= 0;i--)
	{
		if (binary.substr(i, 1) == "1")
			a.binary = a.binary.insert(0, "0");
		else a.binary = a.binary.insert(0, "1");
		count++;
	}
	while (128 - count > 0)
	{
		a.binary.insert(0, "1");
		count++;
	}
	return a;
}
QInt QInt::operator|(QInt a)
{
	QInt c;
	checkBit(*this, a);
	for (int i = 0; i < a.count();i++)
		if (this->binary.substr(i, 1) == "1" || a.binary.substr(i, 1) == "1")
			c.binary += "1";
		else c.binary += "0";
	c.eraze0();
	return c;
}
QInt QInt::operator=(QInt a)
{
	binary = a.binary;
	return *this;
}
QInt QInt::operator&(QInt a)
{
	QInt c;
	checkBit(*this, a);
	for (int i = 0;i < a.count();i++)
	{
		if (a.binary.substr(i, 1) == "1" && this->binary.substr(i, 1) == "1")
			c.binary += "1";
		else c.binary += "0";
	}
	return c;
}
QInt QInt::operator^(QInt a)
{
	QInt c;
	checkBit(*this, a);
	int n = a.count();
	for (int i = 0;i < n;i++)
	{
		if (this->binary.substr(i, 1) == "1" || a.binary.substr(i, 1) == "1" && this->binary.substr(i, 1) != a.binary.substr(i, 1))
			c.binary += "1";
		else c.binary += "0";
	}
	return c;
}
//
void QInt::in(string a)
{
	binary = a;
}
string QInt::show()
{
	return binary;
}
//
long QInt::change10()
{
	long ans = 0;
	int count = QInt::count() - 1;
	if (binary[127] != 1)
		for (int i = count;i >= 0;i--)
			ans = ans + stringtoInt(binary.substr(i, 1)) * pow(2, i);
	else {
		int i;
		for (i = count - 1;i >= 0;i--)
			ans = ans + stringtoInt(binary.substr(i, 1)) * pow(2, i);
		ans = ans - pow(2, count);
	}
	return ans;
}
string check16(int a)
{
	string ans;
	if (a > 9)
	{
		if (a == 10)
			ans = "A";
		else if (a == 11)
			ans = "B";
		else if (a == 12)
			ans = "C";
		else if (a == 13)
			ans = "D";
		else if (a == 14)
			ans = "E";
		else if (a == 15)
			ans = "F";
		else if (a == 16)
			ans = "G";
	}
	else {
		ostringstream os;
		os << a;
		ans = os.str();
	}
	return ans;
}
string QInt::change16()
{
	string ans;
	int count = QInt::count() - 1 + (QInt::count() - 1) % 4;
	// Gia? su? can^` phai? la^'y the^m vai` bit 0 de^? du? 4 bit
	for (int i = count;i >= 0;i = i - 4)
	{
		ans = ans + check16(stringtoInt(binary.substr(i-3)) + stringtoInt(binary.substr(i - 2)) * 2 + stringtoInt(binary.substr(i - 1)) * 4 + stringtoInt(binary.substr(i)) * 8);
		// Do string = string + string1 se~ the^m pha^`n tu? va`o phi'a sau
		// Ne^n xe't tu` tre^n xuo^'ng
	}
	return ans;
}
//
void QInt::ror()
{
	string a = binary.substr(0, 1);
	*this = *this << 1;
	binary.erase(QInt::count() - 1, 1);
	binary += a;
}
void QInt::rol()
{
	string a = binary.substr(QInt::count() - 1, 1);
	*this = *this >> 1;
	binary.insert(0, a);
}
//
void input(const char *in, const  char *out)
{
	long ans1, ans2, totalInt;
	QInt temp1, temp2, total;
	ifstream fin;
	ofstream fout;
	string ans;
	fin.open(in);
	if (!fin.is_open())
		return;
	fout.open(out);
	if (!fout.is_open())
		return;
	while (!fin.eof())
	{
		fin >> ans;
		if (ans == "2")
		{
			fin >> ans;
			if (ans == "10")
			{
				fin >> ans;
				temp1.in(ans);
				fout << temp1.change10() << endl;
			}
			else if (ans == "2")
			{
				fin >> ans;
				fout << ans << endl;
			}
			else if (ans == "16")
			{
				fin >> ans;
				temp1.in(ans);
				fout << temp1.change16() << endl;
			}
			else if (ans == "ror")
			{
				fin >> ans;
				temp1.in(ans);
				temp1.ror();
				fout << temp1.show() << endl;
			}
			else if (ans == "rol")
			{
				fin >> ans;
				temp1.in(ans);
				temp1.rol();
				fout << temp1.show() << endl;
			}
			else if (ans == "~")
			{
				fin >> ans;
				temp1.in(ans);
				temp1 = ~temp1;
				fout << temp1.show() << endl;
			}
			else if (ans == "^")
			{
				fin >> ans;
				temp1.in(ans);
				fin >> ans;
				temp2.in(ans);
				total = temp1 ^ temp2;
				fout << total.show() << endl;
			}
			else if (ans == "|")
			{
				fin >> ans;
				temp1.in(ans);
				fin >> ans;
				temp2.in(ans);
				total = temp1 | temp2;
				fout << total.show() << endl;
			}
			else if (ans == "&")
			{
				fin >> ans;
				temp1.in(ans);
				fin >> ans;
				temp2.in(ans);
				total = temp1 & temp2;
				fout << total.show() << endl;
			}
			else {
				temp1.in(ans);
				fin >> ans;
				if (ans == "+")
				{
					fin >> ans;
					temp2.in(ans);
					total = temp1 + temp2;
					fout << total.show() << endl;
				}
				else if (ans == "-")
				{
					fin >> ans;
					temp2.in(ans);
					total = temp1 - temp2;
					fout << total.show() << endl;
				}
				else if (ans == "*")
				{
					fin >> ans;
					temp2.in(ans);
					total = temp1 * temp2;
					fout << total.show() << endl;
				}
				else if (ans == "/")
				{
					fin >> ans;
					temp2.in(ans);
					total = temp1 / temp2;
					fout << total.show() << endl;
				}
				else;
			}
		}
		else if (ans == "10")
		{
			fin >> ans;
			if (ans == "2")
			{
				;
			}
			else if (ans == "10")
			{
				fin >> ans;
				fout << ans << endl;
			}
			else if (ans == "16")
			{
				;
			}
			else if (ans == "ror")
			{
				;
			}
			else {
				stringstream s(ans);
				s >> ans1;
				fin >> ans;
				if (ans == "+")
				{
					fin >> ans2;
					totalInt = ans1 + ans2;
					fout << totalInt;
					fout << endl;
				}
				else if (ans == "-")
				{
					fin >> ans2;
					totalInt = ans1 - ans2;
					fout << totalInt;
					fout << endl;
				}
				else if (ans == "*")
				{
					fin >> ans2;
					totalInt = ans1 * ans2;
					fout << totalInt;
					fout << endl;
				}
				else if (ans == "/")
				{
					fin >> ans2;
					totalInt = ans1 / ans2;
					fout << totalInt;
					fout << endl;
				}
				else;
			}
		}
		else if (ans == "16")
		{
			fin >> ans;
			if (ans == "10")
			{
				;
			}
			else if (ans == "16")
			{
				fin >> ans;
				fout << ans << endl;
			}
			else if (ans == "2")
			{
				;
			}
			else if (ans == "ror")
			{
				;
			}
			else {
				;
			}
		}
		else;
		fin.close();
		fout.close();
	}
}
void main()
{
	input("input.txt", "output.txt");
	system("pause");
}