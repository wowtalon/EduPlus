#include "global.h"
#include "InsertInfo.h"
#include "delete.h"
#include "query.h"
#include <iostream>
#include <fstream>
#include <string>
#define MAX_LENGTH 100				// �ڴ˴��޸�ÿһ�ж�ȡ������ַ�

//char s_info[] = "students_info.txt";
//char s_grades[] = "students_grades.txt";
//char s_courses[] = "students_courses.txt";

using namespace std;

void print_menu();		// ��ӡѡ��˵� 
void case_function(int);	// �жϲ�ִ���û����� 
void loop();		// ��ѭ�� 
void query_info(string, int);	// ��ѯ��Ϣ 

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
	menu += "|     ����ӭʹ��EduPlusѧ����Ϣ����ϵͳ��        |\n";
	menu += "+------------------------------------------------+\n";
	menu += "| >>��������Ҫִ�еĲ��������س���ִ�У�         |\n";
	menu += "|                                                |\n";
	menu += "|         1. ���һ���µ���Ϣ                    |\n";
	menu += "|         2. ɾ��һ����Ϣ                        |\n";
	menu += "|         3. ��ѯһ����Ϣ                        |\n";
	menu += "|         0. �˳�                                |\n";
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
		cout << "��������Ҫ������ѧ�ţ�" << endl;
		cin >> s_number;
	}
	switch(input_case) {
		case 1:
			cout << "��������Ҫ��ӵ�ѧ����ѧ�ţ��������������ڼ���ϵ��ʽ��ÿһ����Ϣ�Կո����.." << endl;
			cout << "    �磺15551111 ���� 1997.07.01 18812341234" << endl;
			cin >> s_number >> s_name >> s_birth >> s_phone;
			if(insertInfo(s_number, s_name, s_birth, s_phone)) {
				cout << "��ӳɹ�" << endl;
				cout << "��������ͬʱ��Ӹ����ķ�����Ϣ�Ϳγ���Ϣ���Ƿ�������ӣ�(y/n)" << endl;
				cin >> yes_no;
				system("pause");
			} else {
				cout << "����ʧ��" << endl;
				system("pause");
			}
			break;
		case 2:
			if(delete_stu(s_number, s_info)) {
				cout << "�Ƿ�ͬʱɾ�������ķ�����Ϣ�Ϳγ���Ϣ��(y/n)" << endl;
				cin >> yes_no;
				cout << "ɾ���ɹ�" << endl;
				system("pause");
			} else {
				cout << "����ʧ��" << endl;
				system("pause");
			}
			break;
		case 3:
			menu += "+------------------------------------------------+\n";
			menu += "|     ����ӭʹ��EduPlusѧ����Ϣ����ϵͳ��        |\n";
			menu += "+------------------------------------------------+\n";
			menu += "| >>��������Ҫִ�еĲ�ѯ���������س���ִ�У�     |\n";
			menu += "|                                                |\n";
			menu += "|         0. ��ѯѧ����Ϣ                        |\n";
			menu += "|         1. ��ѯѧ������                        |\n";
			menu += "|         2. ��ѯѧ���γ�                        |\n";
			menu += "|         3. ��ѯȫ����Ϣ                        |\n";
			menu += "+------------------------------------------------+";
			system("cls");
			cout << menu << endl;
			cin >> query_method;
			if(query_method >= 0 && query_method <= 3) {
				query_info(s_number, query_method);
			} else {
				cout << "��������ȷָ��..." << endl;
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

