#include "Convert.h"


string StringMulTwo(string num)
{
	string Result;
	int Temp = 0;
	for (int i = 0; i < sizeof(num); i++)
	{
		Temp = Temp * 10 + (num[i] - '0');

		if (i > 0 || (i == 0 && Temp >= 2))
		{
			Result.push_back((Temp / 2) + '0');
		}

		Temp = Temp % 2;
	}
	return Result;
}
string Convert::DecimalToBin(string num)
{
	string Result;
	int m_signed = 0;
	if (num[0] == '-')//kiem tra so am
	{
		num.erase(num.begin());		// bo dau
		m_signed = 1;
	}
	while (num != " ")
	{
		Result.push_back((num[num.size() - 1] - '0') % 2 + '0');
		num = StringMulTwo(num);
	}
	reverse(Result.begin(), Result.end());

	//Nếu là chuỗi ban đầu là số âm.
	if (m_signed == 1)
	{
		

	}
	return Result;
}

string Convert::BintoDecimal(string num)
{
	string Decimal = "0";
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] != '0')
		{
			if (num.size() - i < 128)
			{
				Decimal = add(Decimal, pow(2, num.size() - i - 1));
			}
			else
			{
				Decimal = subtract(Decimal, pow(2, num.size() - i - 1));
			}
		}
	}
	return Decimal;
	
}
string Convert::HexToBin(string num)
{
	string Binary;
	for (int i = 0; i < sizeof(num); i++)
	{
		switch (num[i])
		{
		case '0':
		{
			Binary = Binary + "0000";
			break;
		}
		case '1':
		{
			Binary = Binary + "0001";
			break;
		}
		case '2':
		{
			Binary = Binary + "0010";
			break;
		}
		case '3':
		{
			Binary = Binary + "0011";
			break;
		}
		case '4':
		{
			Binary = Binary + "0100";
			break;
		}
		case '5':
		{
			Binary = Binary + "0101";
			break;
		}
		case '6':
		{
			Binary = Binary + "0110";
			break;
		}
		case '7':
		{
			Binary = Binary + "0111";
			break;
		}
		case '8':
		{
			Binary = Binary + "1000";
			break;
		}
		case '9':
		{
			Binary = Binary + "1001";
			break;
		}
		case 'A':
		{
			Binary = Binary + "1010";
			break;
		}
		case 'B':
		{
			Binary = Binary + "1011";
			break;
		}
		case 'C':
		{
			Binary = Binary + "1100";
			break;
		}
		case 'D':
		{
			Binary = Binary + "1101";
			break;
		}
		case 'E':
		{
			Binary = Binary + "1110";
			break;
		}
		case 'F':
		{
			Binary = Binary + "1111";
			break;
		}
		}
	}

	return Binary;
}
string Convert::BinToHex(string num)
{
	string Temp;
	string Result;

	//them so 0 cho du 4bit
	while (sizeof(num) % 4 != 0)
	{
		num.insert(num.begin(), '0');
	}

	for (int i = 0; i < sizeof(num); i++)
	{
		Temp.push_back(num[i]);

		if (i % 4 == 3)
		{
			if (Temp == "0000")
			{
				Result.push_back('0');
			}
			if (Temp == "0001")
			{
				Result.push_back('1');
			}
			if (Temp == "0010")
			{
				Result.push_back('2');
			}
			if (Temp == "0011")
			{
				Result.push_back('3');

			}
			if (Temp == "0100")
			{
				Result.push_back('4');
			}
			if (Temp == "0101")
			{
				Result.push_back('5');
			}
			if (Temp == "0110")
			{
				Result.push_back('6');
			}
			if (Temp == "0111")
			{
				Result.push_back('7');
			}
			if (Temp == "1000")
			{
				Result.push_back('8');
			}

			if (Temp == "1001")
			{
				Result.push_back('9');
			}
			if (Temp == "1010")
			{
				Result.push_back('A');
			}

			if (Temp == "1011")
			{
				Result.push_back('B');
			}
			if (Temp == "1100")
			{
				Result.push_back('C');
			}

			if (Temp == "1101")
			{
				Result.push_back('D');
			}

			if (Temp == "1110")
			{
				Result.push_back('E');
			}

			if (Temp == "1111")
			{
				Result.push_back('F');
			}


			Temp.clear();  //xong 4bit xoa de xet tiep
		}
	}

	return Result;
}

string Convert::DecimalToHex(string num)
{
	string Result;
	num = DecimalToBin(num);
	Result = BinToHex(num);
	return num;
}
string Convert::HextoDecimal(string num)
{
	string Result;
	num = HexToBin(num);
	Result = BinToHex(num);
	return num;
}


