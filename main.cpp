#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int count;
	bool isEnd;
	struct node *child[26];
}*head;

void init()
{
	head = new node();
	head->isEnd = false;
	head->count = 0;
}

void insert(string word)
{
	node *current = head;
	current->count++;

	for (int i = 0; i < word.length(); i++)
	{
		int letter = (int)word[i] - (int)'a'; //extrct first character of word
		if (current->child[letter] == NULL)
			current->child[letter] = new node();
			current->child[letter]->count++;
			current = current->child[letter];
	}
	current->isEnd = true;
}

bool search(string word)
{
	node *current = head;
	for (int i = 0; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if (current->child[letter] == NULL)
			return false;		//not found
		current = current->child[letter];
	}
	return current->isEnd;
}

int words_with_prefix(string prefix)
{
	node *current = head;
	for (int i = 0; i < prefix.length(); ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		if (current->child[letter] == NULL)
			return 0;
		else
			current = current->child[letter];
	}
	return current->count;
}

void inra(node *current,int b[],int n,string temp)
{
	// Mảng b[] để lưu các mã ASCII của chuỗi ký tự nhập vào
	int count = 0;
	// Biến đếm nếu có ký tự nào tiếp theo
	for (int k = 0;k < n;k++)
		if (current->child[b[k]] != NULL)
		{
			count = 1;
			break;
		}
	if (count == 0)
	{
		// Yêu cầu đề bài: in ra các từ tiếng anh từ 3 ký tự trở lên
		if ((temp.length() >= 3) && (current->isEnd == 1)) // (isEnd) để xác định từ đó đã kết thúc chưa
			cout << temp << endl;
		return;
	}
	for (int i = 0;i < n;i++)
	{
		if (head->count == current->count)
			temp = "";
		// Xoá toàn bộ ký tự khi ký tự đầu tiên thay đổi // VD: eat -> tea
		if (current->child[b[i]] != NULL) // Kiểm tra nếu ký tự tiếp theo có tồn tại
		{
			temp += (char)(b[i] + (int)'a');
			// Thêm ký tự vào cuối 
			inra(current->child[b[i]], b, n, temp);
		}
	}
}

void input()
{
	string a;
	int b[20];
	do {
		cout << "Nhap chuoi ky tu muon check: ";
		cin >> a;
		if (a.length() < 3)
			cout << "Vui long nhap chuoi ky tu gom 3 ky tu tro len!\n";
	} while (a.length() < 3);
	for (int i = 0;i < a.length();i++)
	{
		b[i] = (int)a[i] - (int)'a';
	}
	inra(head, b, a.length(), "");
}

void loadfile(string file_name)
{
	ifstream fin;
	fin.open(file_name);
	if (!fin.is_open())
		return;
	string s;
	while (!fin.eof())
	{
		fin >> s;
		insert(s);
	}
	fin.close();
}

int main()
{
	init();
	loadfile("Dic.txt");
	input();
	system("pause");
	return 0;
}