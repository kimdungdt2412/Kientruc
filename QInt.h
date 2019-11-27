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
	bitset<128> binary;
public:
	QInt();
	QInt add(QInt a, QInt b);
	QInt subtract(QInt a, QInt b);
	QInt multiply(QInt a, QInt b);
	QInt divide(QInt a, QInt b);
	void in(bitset<128> a);
	bitset<128> show();
};

#endif