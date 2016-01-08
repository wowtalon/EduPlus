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
				system("pause");
			} else {
				cout << "����ʧ��" << endl;
				system("pause");
			}
			break;
		case 2:
			if(delete_stu(s_number)) {
				cout << "ɾ���ɹ�" << endl;
				system("pause");
			} else {
				cout << "����ʧ��" << endl;
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
