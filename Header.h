#include <iostream>
#include <string>
#include <math.h>
#include <bitset>

using namespace std;

class QInt
{
private:
	int arrayBits[4];
	bitset<128> binary;
	int size = sizeof(arrayBits);
	int bit = 128;
public:
	QInt();
	QInt add(QInt a, QInt b);
	QInt subtract(QInt a, QInt b);
	QInt multiply(QInt a, QInt b);
	QInt divide(QInt a, QInt b);
	void in(bitset<128> a);
	bitset<128> show();
	bitset<128> add(bitset<128> a, bitset<128> b);
	QInt& operator=(const QInt& b);
	QInt operator >> (const int& a);
	QInt operator << (const int& a);
	QInt operator & (const QInt& a);
	QInt operator | (const QInt& a);
	QInt operator ^ (const QInt& a);
	QInt& operator ~ ();
	QInt& RoL();
	QInt& RoR();
	QInt QInttoTwosComplement(QInt a);

	


};

