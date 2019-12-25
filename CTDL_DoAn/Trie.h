#ifndef _TRIE_
#define _TRIE_

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
};
void init(node *&head);
void insert(node *head,string word);
void countNum(node *current, int b[], int n, string temp, int &countA);
void printEnglish(node *current, int b[], int n, string temp);
void input(node *head);
void loadfile(string file_name, node *head);

#endif