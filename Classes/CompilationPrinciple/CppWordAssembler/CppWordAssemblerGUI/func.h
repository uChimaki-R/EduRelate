#ifndef FUNC_H
#define FUNC_H

#include<iostream>
#include<unordered_set>
#include<fstream>
#include<sstream>
#include<vector>
#include <QFileDialog>
using namespace std;

bool is_keyword(string& token);
bool is_split(char& c);
bool is_operate(char& c);
bool is_word(char& c);
bool is_num(char& c);
void get_lines(ifstream& f, vector<string>& lines);
bool is_identifier(string& token);
string do_assembly(string file_name);

#endif // FUNC_H
