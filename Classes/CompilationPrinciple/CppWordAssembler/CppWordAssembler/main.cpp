#include<iostream>
#include<unordered_set>
using namespace std;

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
	"struct", "switch", "template", "this", "thread_local", "throw",
	"true", "try", "typedef", "typeid", "typename", "union",
	"unsigned", "using", "using", "virtual", "void", "volatile"
};

// 分割符号
unordered_set<string> split = {
	"#", ";", "(", ")", "{", "}", "[", "]", ":", "?", "."
};

// 运算符号
unordered_set<string> operate = {
	"!" ,"%", "^" ,"&", "*" , "-", "+" ,"=",  "|", "~","<", ">","/"
};

int main() {
	return 0;
}