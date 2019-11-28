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
public:
	QInt();
	QInt operator+(QInt a);
	QInt operator-(QInt a);
	QInt operator*(QInt a);
	QInt operator/(QInt a);
	QInt operator=(QInt a);
	QInt operator|(QInt a);
	QInt operator^(QInt a);
	QInt operator&(QInt a);
	QInt operator~(); // ~
	void eraze0();
	void in(string a);
	string show();
	long change10();
	string change16();
	void checkBit(QInt &a, QInt &b);
	void ror();
	void rol();
	int count();
	QInt operator<<(int a);
	QInt operator>>(int a);
};

#endif