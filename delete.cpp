#include "delete.h"
#include "query.h"
#include <fstream>
#include <string>
#define MAX_LENGTH 100
#define S_INFO "students_info.txt"

using namespace std;

// delete a students' info whose student number == stu_number,return 1 if succeed, else return 0
int delete_stu(string stu_number) {
	if(!isexist(stu_number, 0)) {
		return 0;
	} else {
		string str_file = "";
		ifstream if_stu_info;
		if_stu_info.open(S_INFO);
		if(!if_stu_info.is_open()) {
			char str_line[MAX_LENGTH];
			int line = 0;
			while(!if_stu_info.eof()) {
				if_stu_info.getline(str_line, MAX_LENGTH);
				if(line != isexist(stu_number, 0)) {
					str_file += str_line;
					str_file += '\n';
				}
				line++;
			}
		}
		if_stu_info.close();
		ofstream stu_info;
		stu_info.open(S_INFO);
		if(stu_info.is_open()) {
			stu_info << str_file;
			return 1;
		} else {
			return 0;
		}
	}
}
