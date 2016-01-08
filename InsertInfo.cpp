#include "InsertInfo.h"
#include "query.h"
#include <fstream>
#include <string>
#define MAX_LENGTH 100
#define S_INFO "students_info.txt"

using namespace std;

// insert a record into the database, return 0 if succeed, else return 1
int insertInfo(string stu_number, string stu_name, string stu_birth, string stu_phone) {
	if(!isexist(stu_number)) {
		string str_insert= "";
		str_insert += stu_number;
		str_insert += " ";
		str_insert += stu_name;
		str_insert += " ";
		str_insert += stu_birth;
		str_insert += " ";
		str_insert += stu_phone;
		str_insert += '\n';
		string str_file = "";
		ifstream if_stu_info;
		if_stu_info.open(S_INFO);
		while(!if_stu_info.eof()) {
			char c[MAX_LENGTH];
			if_stu_info.getline(c, MAX_LENGTH);
			str_file += c;
			str_file += '\n';
		}
		if_stu_info.close();
		ofstream stu_info;
		stu_info.open(S_INFO);
		str_file += str_insert;
		stu_info << str_file;
		stu_info.close();
		return 0;
	} else {
		return 1;
	}
}
