#include "Trie.h"

int main()
{
	node *head;
	init(head);
	loadfile("Dic.txt", head);
	string a;
	do {
		input(head);
		cout << "--------------\n";
		cout << "Check again?(0 ~ exit): ";
		cin >> a;
		if (a != "0")
			system("cls");
	} while (a != "0");
	cout << "Thank you\n";
	system("pause");
	return 0;
}