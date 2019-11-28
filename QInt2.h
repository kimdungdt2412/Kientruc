#ifndef _QINT_
#define _QINT_
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <bitset>
using namespace std;

class QInt {
private:
	string binary;
	string result;
public:
	QInt();
	string getBinary();
	QInt operator+(QInt a);
	QInt operator-(QInt a);
	QInt operator*(QInt a);
	QInt operator/(QInt a);
	QInt operator=(QInt a);
	QInt operator|(QInt a);
	QInt operator^(QInt a);
	QInt operator&(QInt a);
	QInt operator~(); // ~
	void setBinary(string a);
	QInt QInttoTwosComplement(QInt a);
	void eraze0();
	void in(string a);
	string show();
	long change10();
	string change16();
	string HexToBin();
	string DecimalToBin();
	string DecimalToHex();
	string HextoDecimal();
	void checkBit(QInt& a, QInt& b);
	void ror();
	void rol();
	int count();
	QInt operator<<(int a);
	QInt operator>>(int a);
};

#endif