#include"func.h"

unordered_set<string>identifiers; // 定义的变量标识符

// 关键字
unordered_set<string> keywords = {
	"﻿alignas", "alignof", "andb", "and_eqb", "asma",
	"auto", "bitandb", "bitorb", "bool", "break", "case",
	"catch", "char", "char8_tc", "char16_t", "char32_t", "class",
	"complb", "conceptc", "const", "const_cast", "constevalc", "constexpr",
	"constinitc", "continue", "co_awaitc", "co_returnc", "co_yieldc", "decltype",
	"default", "delete", "do", "double", "dynamic_cast", "else",
	"enum", "explicit", "exportc", "extern", "false", "float",
	"for", "friend", "goto", "if", "inline", "int",
	"long", "mutable", "namespace", "new", "noexcept", "notb",
	"not_eqb", "nullptr", "operator", "orb", "or_eqb", "private",
	"protected", "public", "register", "reinterpret_cast", "requiresc", "return",
	"short", "signed", "sizeof", "static", "static_assert", "static_cast",
    "struct", "switch", "template", "this", "thread_local", "thline",
	"true", "try", "typedef", "typeid", "typename", "union",
	"unsigned", "using", "using", "virtual", "void", "volatile", "main", "include", "define", "cin", "cout", "string"
};
bool is_keyword(string& token) {
	return keywords.count(token);
}

// 分界符号
unordered_set<char> splits = {
	 '(', ')', '{', '}', '[', ']', ',', ';', '.', ':','#'
};
bool is_split(char& c) {
	return splits.count(c);
}

// 运算符号
unordered_set<char> operates = {
	 '+', '-', '*', '/', '=', '!', '<', '>', '&', '|', '^', '%'
};
bool is_operate(char& c) {
	return operates.count(c);
}

// 判断是否字母
bool is_word(char& c) {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

// 判断是否数字
bool is_num(char& c) {
	return c >= '0' && c <= '9';
}


void get_lines(ifstream& f, vector<string>& lines) {
	string line;
	while (getline(f, line)) {
		lines.push_back(line);
	}
}

// 判断是否定义的变量标识符
bool is_identifier(string& token) {
	return identifiers.count(token);
}


string do_assembly(string file_name) {
    string output_string = "";
    // 打开文件
    ifstream f(file_name);
    if (!f.is_open()) {
        return "failed to open file: " + file_name;
    }

    // 读取每行内容
    vector<string>lines;
    get_lines(f, lines);
    f.close();
    /*for (int i = 0; i < lines.size(); i++)cout << lines[i] << endl;
    cout << lines.size();*/

    //
    int size = lines.size();
    for (int line_index = 0; line_index < size; line_index++) {
        string now_token = "";
        for (int i = 0; i < lines[line_index].size(); i++) {
            // 对每行进行分析
            // 保存行列号(从1开始)
            int temp_line_index = line_index + 1;
            if (is_split(lines[line_index][i])) {
                // 分界符号
                // 分界符号可以直接输出，没有特殊情况
                now_token += lines[line_index][i];
                output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t分界符号\n";
                now_token.clear();
            }
            else if (is_operate(lines[line_index][i])) {
                // 运算符号
                // 如果是小于号'<'有两种特殊情况(头文件"<name.h>" 或者 "<标识符")
                if (lines[line_index][i] == '<' && i + 1 < lines[line_index].size() && is_word(lines[line_index][i + 1])) {
                    // 把中间的 文件名/标识符 取出来
                    i++; // 跳过'<'
                    string name = "";
                    while (i < lines[line_index].size() && (is_word(lines[line_index][i]) || lines[line_index][i] == '.')) {
                        // 文件名后缀前有符号'.'，添加判断
                        name += lines[line_index][i];
                        i++;
                    }
                    if (is_identifier(name)) {
                        // 定义的变量标识符
                        output_string += "line[" + to_string(temp_line_index) + "]\t" + name + "\t标识符\n";
                        // 此时i在后面一个位置，此时不能跳过，要让i回来
                        i--;
                    }
                    else {
                        // 头文件直接输出
                        name = "<" + name + ">";
                        output_string += "line[" + to_string(temp_line_index) + "]\t" + name + "\t特殊符号\n";
                        // 此时i在后面一个位置，即'>'，需要跳过
                    }
                }
                // 如果是除号'/'也有两种特殊情况(注解"//"或"/*")
                else if (lines[line_index][i] == '/' && i + 1 < lines[line_index].size() && (lines[line_index][i + 1] == '/' || lines[line_index][i + 1] == '*')) {
                    if (lines[line_index][i + 1] == '/') {
                        // "//"
                        // 直接将该行之后的内容都当作注解
                        i += 2; // 跳过"//"
                        while (i < lines[line_index].size()) {
                            now_token += lines[line_index][i];
                            i++;
                        }
                        now_token = "//" + now_token;
                        output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t注解\n";
                        now_token.clear();
                    }
                    else {
                        // "/*"
                        // 多行注解，要找到下一个"*/"，可能不在同一行
                        i += 2; // 跳过"/*"
                        int pos = lines[line_index].find("*/");
                        if (pos == lines[line_index].npos) {
                            // 这行没有"*/"
                            // 先保存这一行的注解
                            while (i < lines[line_index].size()) {
                                now_token += lines[line_index][i];
                                i++;
                            }
                            line_index++; // 从下一行开始
                            while (line_index < size && (lines[line_index].find("*/") == lines[line_index].npos)) {
                                // 这行没有"*/"
                                now_token += lines[line_index]; // 整行保存
                                line_index++;
                            }
                            // 跳出循环就是这一行有"*/"
                            int pos = lines[line_index].find("*/");
                            i = 0; // 新的行 i置零
                            while (i < pos) {
                                now_token += lines[line_index][i];
                                i++;
                            }
                            i++; // 指向'/'，后面i++会跳过
                            now_token = "/*" + now_token + "*/";
                            output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t注解\n";
                            now_token.clear();
                        }
                        else {
                            // 注解在同一行
                            while (i < pos) {
                                now_token += lines[line_index][i];
                                i++;
                            }
                            i++; // 指向'/'，后面i++会跳过
                            now_token = "/*" + now_token + "*/";
                            output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t注解\n";
                            now_token.clear();
                        }
                    }
                }
                else if (lines[line_index][i] == '-' && i + 1 < lines[line_index].size() && is_num(lines[line_index][i + 1])) {
                    // 负数
                    // 把该token取出来
                    i++; // 跳过'-'
                    while (i < lines[line_index].size() && (is_num(lines[line_index][i]) || lines[line_index][i] == '.' || lines[line_index][i] == 'x' || lines[line_index][i] == 'X' || lines[line_index][i] == 'L' || lines[line_index][i] == 'e' || lines[line_index][i] == 'E')) {
                        // 如果是浮点，数字中间会有'.'
                        if (lines[line_index][i] == 'e' || lines[line_index][i] == 'E') {
                            // 3.45E+3/3.45e3 这种e后面一个都是要的，多加一个
                            now_token += lines[line_index][i];
                            i++;
                        }
                        now_token += lines[line_index][i];
                        i++;
                    }
                    i--; // 回到单词的最后位置，后面还会自己++
                    if (now_token.find('.') != now_token.npos) {
                        // 浮点数
                        output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t浮点数\n";
                        now_token.clear(); // 清空token
                    }
                    else {
                        // 整数
                        output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t整数\n";
                        now_token.clear(); // 清空token
                    }
                }
                else {
                    // 就是单纯的运算符号
                    // 可能是一个(+、-...)两个(+=、>>...)三个(>>=...)
                    // 所以直接一直循环把连续的运算符号找出来
                    while (i < lines[line_index].size() && is_operate(lines[line_index][i])) {
                        now_token += lines[line_index][i];
                        i++;
                    }
                    i--; // 回到最后一个运算符号的位置，后面还会自己++
                    output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t运算符号\n";
                    now_token.clear(); // 清空token
                }
            }
            else if (is_word(lines[line_index][i])) {
                // 第一个是字母说明接下来是一个单词(关键字)或者一个定义的变量标识符
                // 把该token取出来
                while (i < lines[line_index].size() && (is_word(lines[line_index][i]) || is_num(lines[line_index][i]) || lines[line_index][i] == '_')) {
                    // 定义的变量标识符中间可以是数字，所以也要判断
                    now_token += lines[line_index][i];
                    i++;
                }
                i--; // 回到单词的最后位置，后面还会自己++
                // 分两种情况
                if (is_keyword(now_token)) {
                    // 关键字
                    output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t关键字\n";
                    now_token.clear(); // 清空token
                }
                else if (is_identifier(now_token)) {
                    // 定义的变量标识符
                    output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t标识符\n";
                    now_token.clear(); // 清空token
                }
                else {
                    // 是新定义的变量标识符
                    // 需要更新identifiers表
                    identifiers.insert(now_token);
                    output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t标识符\n";
                    now_token.clear(); // 清空token
                }
            }
            else if (is_num(lines[line_index][i])) {
                // 数字
                // 把该token取出来
                while (i < lines[line_index].size() && (is_num(lines[line_index][i]) || lines[line_index][i] == '.' || lines[line_index][i] == 'x' || lines[line_index][i] == 'X' || lines[line_index][i] == 'L' || lines[line_index][i] == 'e' || lines[line_index][i] == 'E')) {
                    // 如果是浮点，数字中间会有'.'
                    if (lines[line_index][i] == 'e' || lines[line_index][i] == 'E') {
                        // 3.45E+3/3.45e3 这种e后面一个都是要的，多加一个
                        now_token += lines[line_index][i];
                        i++;
                    }
                    now_token += lines[line_index][i];
                    i++;
                }
                i--; // 回到单词的最后位置，后面还会自己++
                if (now_token.find('.') != now_token.npos) {
                    // 浮点数
                    output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t浮点数\n";
                    now_token.clear(); // 清空token
                }
                else {
                    // 整数
                    output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t整数\n";
                    now_token.clear(); // 清空token
                }
            }
            else if (lines[line_index][i] == '"') {
                // 字符串
                // 把该token取出来
                i++; // 跳过'"'
                while (i < lines[line_index].size() && lines[line_index][i] != '"') {
                    now_token += lines[line_index][i];
                    i++;
                }
                // 此时i停在了'"'上，后面会自动跳过
                now_token = '"' + now_token + '"';
                output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t字符串\n";
                now_token.clear(); // 清空token
            }
            else if (lines[line_index][i] == '\'') {
                // 字符
                string s(1, lines[line_index][i + 1]);
                s = "'" + s + "'";
                now_token = s;
                output_string += "line[" + to_string(temp_line_index) + "]\t" + now_token + "\t字符\n";
                now_token.clear(); // 清空token
                i += 2;
            }
        }
    }
    return output_string;
}

//int main() {
//	do_assembly("test.txt");
//	cout << output_string;
//	return 0;
//}
