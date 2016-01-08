#include "InsertInfo.h"
#include "delete.h"
#include "query.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print_menu();
void case_function(int);
void loop();

int main() {
	while(true) {
		loop();
	}
	return 0;
}

void loop() {
	print_menu();
	int input_case;
	cin >> input_case;
	case_function(input_case);
}

void print_menu() {
	string menu = "";
	menu += "+------------------------------------------------+\n";
	menu += "|     》欢迎使用EduPlus学生信息管理系统《        |\n";
	menu += "+------------------------------------------------+\n";
	menu += "| >>请输入您要执行的操作，按回车键执行：         |\n";
	menu += "|                                                |\n";
	menu += "|         1. 添加一条新的信息                    |\n";
	menu += "|         2. 删除一条信息                        |\n";
	menu += "|         3. 查询一条信息                        |\n";
	menu += "|         0. 退出                                |\n";
	menu += "+------------------------------------------------+";
	system("cls");
	cout << menu << endl;
}

void case_function(int input_case) {
	string s_number, s_name, s_birth, s_phone;
	if(input_case == 2 || input_case == 3) {
		cout << "请输入您要操作的学号：" << endl;
		cin >> s_number;
	}
	switch(input_case) {
		case 1:
			cout << "请输入您要添加的学生的学号，姓名，出生日期及联系方式，每一项信息以空格隔开.." << endl;
			cout << "    如：15551111 张三 1997.07.01 18812341234" << endl;
			cin >> s_number >> s_name >> s_birth >> s_phone;
			if(insertInfo(s_number, s_name, s_birth, s_phone)) {
				cout << "添加成功" << endl;
				system("pause");
			} else {
				cout << "操作失败" << endl;
				system("pause");
			}
			break;
		case 2:
			if(delete_stu(s_number)) {
				cout << "删除成功" << endl;
				system("pause");
			} else {
				cout << "操作失败" << endl;
				system("pause");
			}
			break;
		case 3:
			stu_query(s_number);
			system("pause");
			break;
		case 0:
			exit(-1);
	}
}
