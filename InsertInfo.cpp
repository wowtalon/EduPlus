#include "global.h"
#include "InsertInfo.h"
#include "query.h"
#include <fstream>
#include <string>
#define MAX_LENGTH 100

using namespace std;

// insert a record into the database, return 1 if succeed, else return 0
int insertInfo(string stu_number, string stu_name, string stu_birth, string stu_phone) {
	if(!isexist(stu_number, 0, s_info)) {
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
		if_stu_info.open(s_info);
		while(!if_stu_info.eof()) {
			char c[MAX_LENGTH];
			if_stu_info.getline(c, MAX_LENGTH);
			str_file += c;
			str_file += '\n';
		}
		if_stu_info.close();
		ofstream stu_info;
		stu_info.open(s_info);
		str_file += str_insert;
		stu_info << str_file;
		stu_info.close();
		return 1;
	} else {
		return 0;
	}
}
