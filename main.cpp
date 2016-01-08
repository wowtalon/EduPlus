#include "global.h"
#include "InsertInfo.h"
#include "delete.h"
#include "query.h"
#include <iostream>
#include <fstream>
#include <string>
#define MAX_LENGTH 100				// 在此处修改每一行读取的最大字符

//char s_info[] = "students_info.txt";
//char s_grades[] = "students_grades.txt";
//char s_courses[] = "students_courses.txt";

using namespace std;

void print_menu();		// 打印选择菜单 
void case_function(int);	// 判断并执行用户命令 
void loop();		// 主循环 
void query_info(string, int);	// 查询信息 

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
	string menu = "";
	char yes_no = 'y';
	int query_method;
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
				cout << "您还可以同时添加该生的分数信息和课程信息，是否现在添加？(y/n)" << endl;
				cin >> yes_no;
				system("pause");
			} else {
				cout << "操作失败" << endl;
				system("pause");
			}
			break;
		case 2:
			if(delete_stu(s_number, s_info)) {
				cout << "是否同时删除该生的分数信息和课程信息？(y/n)" << endl;
				cin >> yes_no;
				cout << "删除成功" << endl;
				system("pause");
			} else {
				cout << "操作失败" << endl;
				system("pause");
			}
			break;
		case 3:
			menu += "+------------------------------------------------+\n";
			menu += "|     》欢迎使用EduPlus学生信息管理系统《        |\n";
			menu += "+------------------------------------------------+\n";
			menu += "| >>请输入您要执行的查询操作，按回车键执行：     |\n";
			menu += "|                                                |\n";
			menu += "|         0. 查询学生信息                        |\n";
			menu += "|         1. 查询学生分数                        |\n";
			menu += "|         2. 查询学生课程                        |\n";
			menu += "|         3. 查询全部信息                        |\n";
			menu += "+------------------------------------------------+";
			system("cls");
			cout << menu << endl;
			cin >> query_method;
			if(query_method >= 0 && query_method <= 3) {
				query_info(s_number, query_method);
			} else {
				cout << "请输入正确指令..." << endl;
				system("pause");
			}
			break;
		case 0:
			exit(-1);
	}
}

void query_info(string s_number, int method) {
	switch(method) {
		case 0:
			query_stu(s_number);
			system("pause");
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			query_stu(s_number);
			system("pause");
			break; 
	}
}

