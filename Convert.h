
#pragma once
#include "Header.h"

class Convert: public QInt
{
public:

	string DecimalToBin(string num);
	string BintoDecimal(string num);
	string HexToBin(string num);
	string BinToHex(string num);
	string DecimalToHex(string num);
	string HextoDecimal(string num);

};

