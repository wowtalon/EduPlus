#include "query.h"
#include <fstream>
#include <iostream>
#include <string>
#define MAX_LENGTH 100
#define S_INFO "students_info.txt"
#define S_GRADES "students_grades.txt"
#define S_COURSES "students_courses.txt"

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
int isexist(string stu_number, int method) {
	ifstream stu_info;
	char str_line[MAX_LENGTH];
	stu_info.open(S_INFO);
	if(stu_info.is_open()) {
		while(!stu_info.eof()) {
			int i, line(0);
			stu_info.getline(str_line, MAX_LENGTH);
			for(i = 0; i < 8; i++, line++) {
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
		}
		if(method == 1) cout << "没有查询到相关信息." << endl;
	}
	stu_info.close();
	return 0;
}

// query a students' info where stu_nember == stu_number, return 0 if succeed, else return 1
int stu_query(string stu_number) {
	isexist(stu_number, 1);
	return 0;
}

int query_course(string stu_number) {
	
}
