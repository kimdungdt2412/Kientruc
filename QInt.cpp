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
bitset<128> QInt::add(bitset<128> a,bitset<128> b) {
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
bitset<128> QInt::subtract(bitset<128> a, bitset<128> b)
{
	b = ~b;
	bitset<128> c(1);
	b = add(b, c);
	c = add(b, a);
	return c;
}
bitset<128> QInt::multiply(bitset<128> a, bitset<128> b) // Du.a tre^n thua^.t toa'n trong slide
{
	int count = countBit(b);
	a = a << count;
	for (int i = count;i > 0;i--)
	{
		if (b[0] == 1)
			b = add(a, b);
		b = (b >> 1);
	}
	return b;
}
bitset<128> QInt::divide(bitset<128> a, bitset<128> b) // Du.a tre^n thua^.t toa'n trong slide
{
	int count = countBit(a); // Vd: 0111 / 0011 (7/3) (Q/M)
	if (a[127] == 0)
		count++; // De^'m ca? bit da^'u (Ne^'u bit 127 = 1 thi` no' la` so^' a^m => da~ ti'nh bit da^'u)
	bitset<128> c(0); // Khoi tao A: 0000
	if (a[127] == 1) // Xe't bit da^'u cuo^'i cu`ng
		c = ~c; // A = -A(1111) ne^'u Q < 0
	bitset<128> d(a); // Khoi tao bie^'n ta.m de^? bo? di pha^`n thu`a cua Q khi di.ch tra'i
	for (int i = count;i > 0;i--)
	{
		a = a << 1; // 1110
		c = c << 1; // 0000
		if (a[count] == 1)
			c[0] = 1; // Khi di.ch tra'i Q sang 1 don vi., ne^'u di.ch qua vi. tri' bit da^'u +1
					  // thi` gan' qua A[0] nhu thua^.t toa'n slide
		d = d << 1;
		c = subtract(c, b); // 0000 - 0011 ~ 00000000 - 00110000
		if (c[127] == 1)
			c = add(c, b); // Kho^i phu.c ne^'u A < 0
		else { 
			a[0] = 1; // Q[0] = 1
		}
	}
	a = subtract(a, d);
	return a;
}
void input(const char *path, int arr[])
{
	system("pause");
}
void main()
{
	int arr[4];
	input("input.txt", arr);
}