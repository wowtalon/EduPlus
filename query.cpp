#include "global.h"
#include "query.h"
#include <fstream>
#include <iostream>
#include <string>
#define MAX_LENGTH 800		// 在此处修改每一行读取的最大字符

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
/* 
	此函数用来判断所查询的学号是否存在，使用此函数时需要提供学号以及查询方式，查询方式分两种：
	0. 仅查询此学号是否存在，若存在则返回该生信息所在行数，否则返回 0
	1. 查询此学号是否存在，若存在则返回行数同时输出该生信息，否则输出提示无相关信息，返回 0 
*/ 
int isexist(string &stu_number, int method, char * query_file) {
	ifstream stu_info;
	int line = 1;
	char str_line[MAX_LENGTH];
	stu_info.open(query_file);
	if(stu_info.is_open()) {
		while(!stu_info.eof()) {
			int i;
			stu_info.getline(str_line, MAX_LENGTH);
			for(i = 0; i < 8; i++) {
				if(stu_number[i] != str_line[i]) {
					break;
				}
			}
			if(i == 8) {
				stu_info.close();
				if(method == 1) {
					cout << "查询到：" << endl;
					cout << str_line << endl;
				}
				return line;
				break;
			}
			line++;
		}
		if(method == 1) cout << "没有查询到相关信息." << endl;
	}
	stu_info.close();
	return 0;
}

// 用以直接查询学生课程信息的isexist重载函数，查询到相关信息时返回学生课程信息，否则返回404
char *isexist(string &stu_number, char * query_file) {
	ifstream stu_info;
	int line = 1;
	char *str_linel = new char[MAX_LENGTH];
	stu_info.open(query_file);
	if (stu_info.is_open()) {
		while (!stu_info.eof()) {
			int i;
			stu_info.getline(str_linel, MAX_LENGTH);
			for (i = 0; i < 8; i++) {
				if (stu_number[i] != str_linel[i]) {
					break;
				}
			}
			if (i == 8) {
				stu_info.close();
				return str_linel;
				break;
			}
			line++;
		}
	}
	stu_info.close();
	return "404";
}

// query a students' info where stu_nember == stu_number, return 0 if succeed, else return 1
// 直接调用query方法指定查询方式为 1 
int query_stu(string &stu_number) {
	isexist(stu_number, 1, s_info);
	return 0;
}

// 用以查询课程信息 
int query_course(string &stu_number) {
	ifstream stu_courses;
	char *str_line = isexist(stu_number, s_courses);
	if (str_line[0] != '4') {
		int i = 0;
		while (str_line[i] != '\0') {
			cout << str_line[i];
			i++;
		}
		cout << endl;
		return 1;
	}
	else {
		cout << "抱歉，暂未查到该生的相关信息！" << endl;
		return 0;
	}
}

// 用以查询课程信息 
int query_grade(string &stu_number) {
	ifstream stu_courses;
	char *str_line = isexist(stu_number, s_grades);
	if (str_line[0] != '4') {
		int i = 0;
		while (str_line[i] != '\0') {
			cout << str_line[i];
			i++;
		}
		cout << endl;
		return 1;
	}
	else {
		cout << "抱歉，暂未查到该生的相关信息！" << endl;
		return 0;
	}
}
