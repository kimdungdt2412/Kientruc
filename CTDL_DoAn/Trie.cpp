#include "Trie.h"
void init(node *&head)
{
	head = new node();
	head->isEnd = false;
	head->count = 0;
}
void insert(node *head,string word)
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
void countNum(node *current, int b[], int n, string temp, int &countA)
{
	// Mảng b[] để lưu các mã ASCII của chuỗi ký tự nhập vào
	int count = 0;
	// Kiểm tra xem có "các ký tự trong chuỗi" ở phía sau không
	for (int i = 0;i < n;i++)
		if (current->child[b[i]] != NULL)
			count++;
	if (current->isEnd) // (isEnd) để xác định từ đó đã kết thúc chưa
	{	// Yêu cầu đề bài: in ra các từ tiếng anh từ 3 ký tự trở lên
		if (temp.length() >= 3)
			countA++;
	}
	// Nếu không có ký tự nào ở phía sau thì chuyển sang ký tự tiếp theo
	if (count == 0)
		return;
	for (int i = 0;i < n;i++)
	{
		if (current->child[b[i]] != NULL) // Kiểm tra nếu ký tự tiếp theo có tồn tại
		{
			// Thêm ký tự vào cuối
			temp += (char)(b[i] + (int)'a');
			countNum(current->child[b[i]], b, n, temp, countA);
			// Xoá ký tự khi đã duyệt qua để tránh bị trùng
			temp.erase(temp.begin() + (temp.length() - 1));
		}
	}
}
void printEnglish(node *current, int b[], int n, string temp)
{
	// Mảng b[] để lưu các mã ASCII của chuỗi ký tự nhập vào
	int count = 0;
	// Kiểm tra xem có "các ký tự trong chuỗi" ở phía sau không
	for (int i = 0;i < n;i++)
		if (current->child[b[i]] != NULL)
			count++;
	if (current->isEnd) // (isEnd) để xác định từ đó đã kết thúc chưa
	{	// Yêu cầu đề bài: in ra các từ tiếng anh từ 3 ký tự trở lên
		if (temp.length() >= 3)
			cout << temp << endl;
	}
	// Nếu không có ký tự nào ở phía sau thì chuyển sang ký tự tiếp theo
	if (count == 0)
		return;
	for (int i = 0;i < n;i++)
	{
		if (current->child[b[i]] != NULL) // Kiểm tra nếu ký tự tiếp theo có tồn tại
		{
			// Thêm ký tự vào cuối
			temp += (char)(b[i] + (int)'a');
			printEnglish(current->child[b[i]], b, n, temp);
			// Xoá ký tự khi đã duyệt qua để tránh bị trùng
			temp.erase(temp.begin() + (temp.length() - 1));
		}
	}
}
void input(node *head)
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
	int count = 0;
	countNum(head, b, a.length(), "", count);
	cout << count << endl;
	printEnglish(head, b, a.length(), "");
}
void loadfile(string file_name,node *head)
{
	ifstream fin;
	fin.open(file_name);
	if (!fin.is_open())
		return;
	string s;
	while (!fin.eof())
	{
		fin >> s;
		insert(head,s);
	}
	fin.close();
}