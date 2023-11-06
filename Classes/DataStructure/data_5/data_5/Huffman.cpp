#include"Huffman.h"

void init(map<char, int>& freq) {
	cout << "Code counts:";
	int n, f;
	char code;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		getchar();
		cout << "code_" << i << ":";
		code = getchar();
		cout << "freq:";
		cin >> f;
		freq[code] += f;
	}
}

Node* buildHuffmanTree(map<char, int>& freq) {
	//小顶堆 权重小的在堆顶
	priority_queue<Node*, vector<Node*>, Compare> pq;

	//每个点存入堆
	for (auto it : freq) {
		pq.push(new Node(it.first, it.second, nullptr, nullptr));
	}

	//循环建树
	while (pq.size() != 1) {
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();
		int sum = left->freq + right->freq;
		pq.push(new Node('\0', sum, left, right));
	}

	//返回根节点
	return pq.top();
}

void encode(Node* root, string str, map<char, string>& huffmanCode) {
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}
	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

void printHuffmanCode(map<char, string>& huffmanCode) {
	cout << "Huffman Codes:" << endl;
	for (auto it : huffmanCode) {
		cout << it.first << " " << it.second << endl;
	}
}

string decode(Node* root, int& index, const string& s) {
	if (root == nullptr) {
		return "";
	}
	if (!root->left && !root->right) {
		return string(1, root->ch);
	}
	index++;
	if (s[index] == '0') {
		return decode(root->left, index, s);
	}
	else {
		return decode(root->right, index, s);
	}
}

string decText(string& encodedText, Node* root) {
	int index = -1;
	string decodedText = "";
	while (index <= (int)encodedText.size() - 2) {
		decodedText += decode(root, index, encodedText);
	}
	return decodedText;
}

string encText(string& text, map<char, string>& huffmanCode) {
	string encodedText = "";
	for (char ch : text) {
		encodedText += huffmanCode[ch];
	}
	return encodedText;
}

bool saveHuffman(map<char, int>& freq, string fileName) {
	ofstream f(fileName);
	if (f.is_open()) {
		for (auto it : freq) {
			f << it.first << " " << it.second << endl;
		}
		f.close();
		return true;
	}
	else return false;
}

bool readHuffman(map<char, int>& freq, string fileName) {
	ifstream f(fileName);
	char c;
	int t;
	if (f.is_open()) {
		while (!f.eof() && f.peek() != EOF) {
			c = f.get();
			f >> t;
			f.get();
			freq[c] = t;
		}
		f.close();
		return true;
	}
	else return false;
}