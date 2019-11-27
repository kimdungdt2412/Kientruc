#include "QInt.h"
void printBit(bitset<128> c)
{
	int i = 127;
	while (c[i] == 0)
	{
		i--;
	}
	// Loai. nhung~ so^' 0 khong can thiet
	while (i != -1)
	{
		cout << c[i];
		i--;
	}
	cout << endl;
}
int countBit(bitset<128> c)
{
	int count = 1;
	int i = 127;
	while (c[i] == 0)
	{
		i--;
	}
	while (i != 0)
	{
		count++;
		i--;
	}
	return count;
}
int countBit2(bitset<128> a, bitset<128> b)
{
	int count = 1;
	int i = 127;
	while (a[i] == 0 && b[i] == 0)
	{
		i--;
	}
	// Loai. nhung~ so^' 0 khong can thiet
	// De^'m so^' phan^` tu? trong day~ so^' lon' nha^'t giua~ 2 day~ so^'
	while (i != 0)
	{
		count++;
		i--;
	}
	return count;
}
QInt::QInt()
{
	;
}
// Nhung~ ham` +-*/ kho^ng ta'c do^.ng de^'n gia' tri. cu?a QInt go^'c
QInt QInt::add(QInt a,QInt b) {
	int du, d, s;
	QInt c;
	int count = countBit2(a.binary, b.binary) - 1;
	du = 0; // So^' ca^`n nho' VD: 1 + 1 = 0 nho' 1
	for (int j = 0; j <= count; j++) {
		d = (a.binary[j] + b.binary[j] + du) / 2; // Tim so^' can^` nho' sau khi co^.ng
		s = a.binary[j] + b.binary[j] + du - 2 * d; // Gia tri sau khi co^.ng
		c.binary[j] = s; // Luu ket qua
		du = d;
	}
	return c;
}
QInt QInt::subtract(QInt a, QInt b)
{
	b.binary = ~b.binary;
	QInt c;
	c.binary[0] = 1;
	b = add(b, c);
	c = add(b, a);
	return c;
}
QInt QInt::multiply(QInt a, QInt b) // Du.a tre^n thua^.t toa'n trong slide
{
	int count = countBit(b.binary);
	a.binary = a.binary << count;
	for (int i = count;i > 0;i--)
	{
		if (b.binary[0] == 1)
			b = add(a, b);
		b.binary = (b.binary >> 1);
	}
	return b;
}
QInt QInt::divide(QInt a, QInt b) // Du.a tre^n thua^.t toa'n trong slide
{
	int count = countBit(a.binary); // Vd: 0111 / 0011 (7/3) (Q/M)
	if (a.binary[127] == 0)
		count++; // De^'m ca? bit da^'u (Ne^'u bit 127 = 1 thi` no' la` so^' a^m => da~ ti'nh bit da^'u)
	QInt c; // Khoi tao A: 0000
	if (a.binary[127] == 1) // Xe't bit da^'u cuo^'i cu`ng
		c.binary = ~c.binary; // A = -A(1111) ne^'u Q < 0
	QInt d = a; // Khoi tao bie^'n ta.m de^? bo? di pha^`n thu`a cua Q khi di.ch tra'i
	for (int i = count;i > 0;i--)
	{
		a.binary = a.binary << 1; // 1110
		c.binary = c.binary << 1; // 0000
		if (a.binary[count] == 1)
			c.binary[0] = 1; // Khi di.ch tra'i Q sang 1 don vi., ne^'u di.ch qua vi. tri' bit da^'u +1
					  // thi` gan' qua A[0] nhu thua^.t toa'n slide
		d.binary = d.binary << 1;
		c = subtract(c, b); // 0000 - 0011 ~ 00000000 - 00110000
		if (c.binary[127] == 1)
			c = add(c, b); // Kho^i phu.c ne^'u A < 0
		else { 
			a.binary[0] = 1; // Q[0] = 1
		}
	}
	a = subtract(a, d);
	return a;
}
//
void QInt::in(bitset<128> a)
{
	// Ga'n gia' tri., do khai ba'o bitset tu` string chi? vie^'t duo.c duoi' da.ng:
	// bitset<128> a(string);
	// Xem trong ha`m input se~ hie^?u
	binary = a;
}
bitset<128> QInt::show()
{
	return binary;
}
void input(const char *in, const  char *out)
{
	int ans1, ans2, totalInt;
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
				;
			}
			else if (ans == "8")
			{
				;
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
				bitset<128> a(ans);
				temp1.in(a);
				fin >> ans;
				if (ans == "+")
				{
					fin >> ans;
					bitset<128> b(ans);
					temp2.in(b);
					total = total.add(temp1, temp2);
					int i = 127;
					while (total.show()[i] == 0)
					{
						i--;
					}
					// Loai. nhung~ so^' 0 khong can thiet
					while (i != -1)
					{
						fout << total.show()[i];
						i--;
					}
					fout << endl;
				}
				else if (ans == "-")
				{
					fin >> ans;
					bitset<128> b(ans);
					temp2.in(b);
					total = total.subtract(temp1, temp2);
					int i = 127;
					while (total.show()[i] == 0)
					{
						i--;
					}
					// Loai. nhung~ so^' 0 khong can thiet
					while (i != -1)
					{
						fout << total.show()[i];
						i--;
					}
					fout << endl;
				}
				else if (ans == "*")
				{
					fin >> ans;
					bitset<128> b(ans);
					temp2.in(b);
					total = total.multiply(temp1, temp2);
					int i = 127;
					while (total.show()[i] == 0)
					{
						i--;
					}
					// Loai. nhung~ so^' 0 khong can thiet
					while (i != -1)
					{
						fout << total.show()[i];
						i--;
					}
					fout << endl;
				}
				else if (ans == "/")
				{
					fin >> ans;
					bitset<128> b(ans);
					temp2.in(b);
					total = total.divide(temp1, temp2);
					int i = 127;
					while (total.show()[i] == 0)
					{
						i--;
					}
					// Loai. nhung~ so^' 0 khong can thiet
					while (i != -1)
					{
						fout << total.show()[i];
						i--;
					}
					fout << endl;
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
			else if (ans == "8")
			{
				;
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
		else if (ans == "8")
		{
			fin >> ans;
			if (ans == "10")
			{
				;
			}
			else if (ans == "2")
			{
				;
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
				;
			}
		}
		else if (ans == "16")
		{
			fin >> ans;
			if (ans == "10")
			{
				;
			}
			else if (ans == "8")
			{
				;
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