#include "Header.h"

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
QInt QInt::add(QInt a, QInt b) {
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
QInt QInt::QInttoTwosComplement(QInt a)
{
	QInt Result;
	a.binary = ~a.binary;
	QInt c;
	c.binary[0] = 1;
	Result = add(a, c);
	return Result;
}
QInt QInt::multiply(QInt a, QInt b) // Du.a tre^n thua^.t toa'n trong slide
{
	int count = countBit(b.binary);
	a.binary = a.binary << count;
	for (int i = count; i > 0; i--)
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
	for (int i = count; i > 0; i--)
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
bitset<128> QInt::add(bitset<128> a, bitset<128> b) {
	int du, d, s, j;
	bitset <128> c;
	int count = countBit2(a, b) - 1;
	du = 0; // So^' ca^`n nho' VD: 1 + 1 = 0 nho' 1
	for (j = 0; j <= count; j++) {
		d = (a[j] + b[j] + du) / 2; // Tim so^' can^` nho' sau khi co^.ng
		s = a[j] + b[j] + du - 2 * d; // Gia tri sau khi co^.ng
		c[j] = s; // Luu ket qua
		du = d;
	}
	return c;
}
QInt QInt::operator & (const QInt& a)
{
	QInt Result;

	for (int i = 0; i < size; i++)
	{
		Result.arrayBits[i] = this->arrayBits[i] & a.arrayBits[i];
	}

	return Result;
}
QInt QInt::operator | (const QInt& a)
{
	QInt Result;
	for (int i = 0; i < size; i++)
	{
		Result.arrayBits[i] = this->arrayBits[i] | a.arrayBits[i];
	}

	return Result;

}
QInt QInt::operator ^ (const QInt& a)
{
	QInt Result;
	for (int i = 0; i < size; i++)
	{
		Result.arrayBits[i] = this->arrayBits[i] ^ a.arrayBits[i];
	}

	return Result;

}
QInt& QInt::operator ~ ()
{
	for (int i = 0; i < size; i++)
	{
		this->arrayBits[i] = ~this->arrayBits[i];
	}

	return *this;

}
QInt& QInt::operator=(const QInt& b)
{
	for (int i = 0; i < size; i++)
	{
		arrayBits[i] = b.arrayBits[i];
	}

	return *this;
}
QInt QInt::operator >> (const int& a)
{
	QInt Result;
	Result.arrayBits[0] = this->arrayBits[0] >> a;

	for (int i = 1; i < this->size; i++)
	{
		for (int j = 0; j < a; j++)
		{
			Result.arrayBits[i - 1] = Result.arrayBits[i - 1] | (((1 << j) & this->arrayBits[i]) << (bit - a + j));
		}

		Result.arrayBits[i] = this->arrayBits[i] >> a; 
	}



	return Result;
}
QInt QInt::operator << (const int& a)
{
	QInt Result;
	Result.arrayBits[Result.size - 1] = this->arrayBits[size - 1] << a;
	for (int i = size - 2; i > -1; i--)
	{
		//Đưa các bit tràn ra ngoài vào phần block 4 bytes cao hơn.
		for (int j = 0; j < a; j++)
		{
			Result.arrayBits[i + 1] = Result.arrayBits[i + 1] | (((1 << (128 - j - 1)) & this->arrayBits[i]) >> (128- a));
		}

		Result.arrayBits[i] = this->arrayBits[i] << a; //Tiến hành dịch bit.
	}

	return Result;
}
QInt& QInt::RoL()
{
	//Lưu bit bị đẩy ra ngoài.
	int TempBit = (1 << (bit - 1)) & this->arrayBits[size - 1];
	*this = *this << 1; //Dịch trái 1 bit.
	this->arrayBits[0] = this->arrayBits[0] | (TempBit >> (bit - 1)); //Chèn bit vùa bị đẩy ra vào.

	return *this;
}

//Phép toán xoay phải.
QInt& QInt::RoR()
{
	//Lưu bit bị đẩy ra ngoài.
	int TempBit = 1 & this->arrayBits[0];
	*this = *this >> 1; //Dịch phải 1 bit.
	this->arrayBits[size - 1] = this->arrayBits[size - 1] | (TempBit << (size - 1)); //Chèn bit vùa bị đẩy ra vào.

	return *this;
}
///////////////////////////////////////////////////////////////////
