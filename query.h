#ifndef INCLUDED_H_QUERY
#define INCLUDED_H_QUERY

#include <string>

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
/* 
	�˺��������ж�����ѯ��ѧ���Ƿ���ڣ�ʹ�ô˺���ʱ��Ҫ�ṩѧ���Լ���ѯ��ʽ����ѯ��ʽ�����֣�
	0. ����ѯ��ѧ���Ƿ���ڣ��������򷵻ظ�����Ϣ�������������򷵻� 0
	1. ��ѯ��ѧ���Ƿ���ڣ��������򷵻�����ͬʱ���������Ϣ�����������ʾ�������Ϣ������ 0 
*/ 
int isexist(string stu_number, int method, char * query_file);

// query a students' info where stu_nember == stu_number, return 0 if succeed, else return 1
int query_stu(string stu_number);

int query_course(string stu_number);
 
#endif
