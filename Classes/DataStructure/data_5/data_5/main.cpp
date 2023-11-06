#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "Huffman.h"
using namespace std;

int main() {
	string command;
	while (true) {
		cout << "Enter command (I/E/D/P/T/Q): ";
		cin >> command;
		if (command == "I") {
			map<char, int> freq;

			//统计频率
			init(freq);

			////建立哈夫曼树
			//Node* root = buildHuffmanTree(freq);
			//cout << "Successfully established Huffman tree." << endl;

			////获取字符编码
			//map<char, string> huffmanCode;
			//encode(root, "", huffmanCode);

			//保存哈夫曼编码(字符频率)
			if (saveHuffman(freq, "hfmTree.txt")) cout << "Successfully saved Huffman tree to file hfmTree.txt." << endl;
			else cout << "Unable to save Huffman tree to file hfmTree.txt." << endl;
		}
		else if (command == "E") {
			map<char, int> freq;

			//读取哈夫曼编码
			if (!readHuffman(freq, "hfmTree.txt"))cout << "Unable to read Huffman tree from file hfmTree.txt." << endl;
			else {
				//读取待编码的文本
				ifstream f("ToBeTran.txt");
				if (f.is_open()) {
					string text;
					getline(f, text);
					cout << "Text in ToBeTran.txt: " << text << endl;

					//建立哈夫曼树
					Node* root = buildHuffmanTree(freq);

					//获取字符编码
					map<char, string> huffmanCode;
					encode(root, "", huffmanCode);

					//对文本进行编码
					string encodedText = encText(text, huffmanCode);
					cout << "Encoded Text: " << encodedText << endl;
					f.close();

					//保存编码后的文本
					ofstream out("CodeFile.txt");
					if (out.is_open()) {
						out << encodedText << endl;
						cout << "Successfully save to file CodeFile.txt." << endl;
						out.close();
					}
					else cout << "Could not open file CodeFile.txt." << endl;
				}
				else cout << "Could not open file ToBeTran.txt." << endl;
			}
		}
		else if (command == "D") {
			map<char, int> freq;

			//读取哈夫曼编码
			if (!readHuffman(freq, "hfmTree.txt"))cout << "Unable to read Huffman tree from file hfmTree.txt" << endl;
			else {
				//读取待译码的文本
				ifstream f("CodeFile.txt");
				if (f.is_open()) {
					string text;
					getline(f, text);
					cout << "Text in CodeFile.txt: " << text << endl;

					//建立哈夫曼树
					Node* root = buildHuffmanTree(freq);

					//对文本进行译码
					string decodedText = decText(text, root);
					cout << "Decoded Text: " << decodedText << endl;
					f.close();

					//保存编码后的文本
					ofstream out("Textfile.txt");
					if (out.is_open()) {
						out << decodedText << endl;
						cout << "Successfully save to file Textfile.txt." << endl;
						out.close();
					}
					else cout << "Could not open file Textfile.txt." << endl;
				}
				else cout << "Could not open file CodeFile.txt." << endl;
			}
		}
		else if (command == "P") {
			ifstream f("CodeFile.txt");
			if (f.is_open()) {
				string text;
				getline(f, text);
				cout << "Text in CodeFile.txt: ";
				for (int i = 0; i < text.length(); i++) {
					if (i % 50)cout << text[i];
					else cout << endl;
				}
				cout << endl;
				f.close();
			}
			else cout << "Could not open file CodeFile.txt." << endl;
		}
		else if (command == "T") {
			map<char, int> freq;

			//读取哈夫曼编码
			if (!readHuffman(freq, "hfmTree.txt"))cout << "Unable to read Huffman tree from file hfmTree.txt" << endl;
			else {
				//建立哈夫曼树
				Node* root = buildHuffmanTree(freq);
				map<char, string> huffmanCode;
				encode(root, "", huffmanCode);

				cout << "huffmanCode:" << endl;
				for (auto i : huffmanCode) {
					cout << i.first << ": " << i.second << endl;
				}
			}
		}
		else if (command == "Q") {
			cout << "Program exit, thank you for using." << endl;
			break;
		}
		else {
			cout << "Invalid command!" << endl;
		}
		system("pause");
		system("cls");
	}
	return 0;
}


int main_test() {
	map<char, int> freq;

	//统计频率
	init(freq);

	//建立哈夫曼树
	Node* root = buildHuffmanTree(freq);

	//获取字符编码
	map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	//打印哈夫曼编码
	printHuffmanCode(huffmanCode);

	//根据输入获取编码后的01序列
	cout << "TextToEnc: ";
	string text;
	cin >> text;

	string encodedText = encText(text, huffmanCode);
	cout << "Encoded Text: " << encodedText << endl;

	//将01序列通过哈夫曼编码解码
	string decodedText = decText(encodedText, root);
	cout << "Decoded Text: " << decodedText << endl;

	return 0;
}
