#include "global.h"
#include "query.h"
#include <fstream>
#include <iostream>
#include <string>
#define MAX_LENGTH 800		// �ڴ˴��޸�ÿһ�ж�ȡ������ַ�

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
/* 
	�˺��������ж�����ѯ��ѧ���Ƿ���ڣ�ʹ�ô˺���ʱ��Ҫ�ṩѧ���Լ���ѯ��ʽ����ѯ��ʽ�����֣�
	0. ����ѯ��ѧ���Ƿ���ڣ��������򷵻ظ�����Ϣ�������������򷵻� 0
	1. ��ѯ��ѧ���Ƿ���ڣ��������򷵻�����ͬʱ���������Ϣ�����������ʾ�������Ϣ������ 0 
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
					cout << "��ѯ����" << endl;
					cout << str_line << endl;
				}
				return line;
				break;
			}
			line++;
		}
		if(method == 1) cout << "û�в�ѯ�������Ϣ." << endl;
	}
	stu_info.close();
	return 0;
}

// ����ֱ�Ӳ�ѯѧ���γ���Ϣ��isexist���غ�������ѯ�������Ϣʱ����ѧ���γ���Ϣ�����򷵻�404
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
// ֱ�ӵ���query����ָ����ѯ��ʽΪ 1 
int query_stu(string &stu_number) {
	isexist(stu_number, 1, s_info);
	return 0;
}

// ���Բ�ѯ�γ���Ϣ 
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
		cout << "��Ǹ����δ�鵽�����������Ϣ��" << endl;
		return 0;
	}
}

// ���Բ�ѯ�γ���Ϣ 
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
		cout << "��Ǹ����δ�鵽�����������Ϣ��" << endl;
		return 0;
	}
}
