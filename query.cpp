#include "global.h"
#include "query.h"
#include <fstream>
#include <iostream>
#include <string>
#define MAX_LENGTH 100				// �ڴ˴��޸�ÿһ�ж�ȡ������ַ�

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
/* 
	�˺��������ж�����ѯ��ѧ���Ƿ���ڣ�ʹ�ô˺���ʱ��Ҫ�ṩѧ���Լ���ѯ��ʽ����ѯ��ʽ�����֣�
	0. ����ѯ��ѧ���Ƿ���ڣ��������򷵻ظ�����Ϣ�������������򷵻� 0
	1. ��ѯ��ѧ���Ƿ���ڣ��������򷵻�����ͬʱ���������Ϣ�����������ʾ�������Ϣ������ 0 
*/ 
int isexist(string stu_number, int method, char * query_file) {
	ifstream stu_info;
	char str_line[MAX_LENGTH];
	stu_info.open(query_file);
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
					cout << "��ѯ����" << endl;
					cout << str_line << endl;
				}
				return line;
				break;
			}
		}
		if(method == 1) cout << "û�в�ѯ�������Ϣ." << endl;
	}
	stu_info.close();
	return 0;
}

// query a students' info where stu_nember == stu_number, return 0 if succeed, else return 1
// ֱ�ӵ���query����ָ����ѯ��ʽΪ 1 
int query_stu(string stu_number) {
	isexist(stu_number, 1, s_info);
	return 0;
}

// ���Բ�ѯ�γ���Ϣ 
int query_course(string stu_number) {
	
}
