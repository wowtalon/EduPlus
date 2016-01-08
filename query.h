#ifndef INCLUDED_H_QUERY
#define INCLUDED_H_QUERY

#include <string>

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
/* 
	此函数用来判断所查询的学号是否存在，使用此函数时需要提供学号以及查询方式，查询方式分两种：
	0. 仅查询此学号是否存在，若存在则返回该生信息所在行数，否则返回 0
	1. 查询此学号是否存在，若存在则返回行数同时输出该生信息，否则输出提示无相关信息，返回 0 
*/ 
int isexist(string stu_number, int method, char * query_file);

// query a students' info where stu_nember == stu_number, return 0 if succeed, else return 1
int query_stu(string stu_number);

int query_course(string stu_number);
 
#endif
