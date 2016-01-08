#include "InsertInfo.h"
#include "delete.h"
#include "query.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	string s = "15551111 张三 1997.07.01 18812341234\n15551112 李四 1997.07.02 18812341235";
	ofstream stu_info;
	stu_info.open("students_info.txt");
	if(stu_info.is_open()) {
		stu_info << s;
	} else {
		cout << "error!";
	}
	return 0;
}
