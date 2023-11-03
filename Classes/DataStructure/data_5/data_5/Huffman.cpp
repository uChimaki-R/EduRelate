#include"Huffman.h"

void init(unordered_map<char, int>& freq) {
	cout << "Code counts:";
	int n, f;
	char code;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "code_" << i << ":";
		cin >> code;
		cout << "freq:";
		cin >> f;
		freq[code] += f;
	}
}

Node* buildHuffmanTree(unordered_map<char, int>& freq) {
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

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}
	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

void printHuffmanCode(unordered_map<char, string>& huffmanCode) {
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

string encText(string& text, unordered_map<char, string>& huffmanCode) {
	string encodedText = "";
	for (char ch : text) {
		encodedText += huffmanCode[ch];
	}
	return encodedText;
}

bool saveHuffman(unordered_map<char, int>& freq, string fileName) {
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

bool readHuffman(unordered_map<char, int>& freq, string fileName) {
	ifstream f(fileName);
	char c;
	int t;
	if (f.is_open()) {
		while (!f.eof() && f.peek() != EOF) {
			f >> c >> t;
			freq[c] = t;
		}
		f.close();
		return true;
	}
	else return false;
}