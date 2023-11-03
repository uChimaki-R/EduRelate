#pragma once
#include <iostream>
#include <unordered_map>
#include <queue>
#include <fstream>
using namespace std;

struct Node {
	char ch;
	int freq;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(char ch, int freq, Node* left, Node* right) : ch(ch), freq(freq), left(left), right(right) {}
};

struct Compare {
	bool operator()(Node* a, Node* b) {
		return a->freq > b->freq;
	}
};

void init(unordered_map<char, int>& freq);

Node* buildHuffmanTree(unordered_map<char, int>& freq);

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode);

void printHuffmanCode(unordered_map<char, string>& huffmanCode);

string decode(Node* root, int& index, const string& s);

string decText(string& encodedText, Node* root);

string encText(string& text, unordered_map<char, string>& huffmanCode);

bool saveHuffman(unordered_map<char, int>& freq, string fileName);

bool readHuffman(unordered_map<char, int>& freq, string fileName);
