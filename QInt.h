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
	bitset<128> add(bitset<128> a, bitset<128> b);
	bitset<128> subtract(bitset<128> a, bitset<128> b);
	bitset<128> multiply(bitset<128> a, bitset<128> b);
	bitset<128> divide(bitset<128> a, bitset<128> b);
};

#endif