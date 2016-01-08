#ifndef INCLUDED_H_QUERY
#define INCLUDED_H_QUERY

#include <string>

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
int isexist(string stu_number, int method);

// query a students' info where stu_nember == stu_number, return 0 if succeed, else return 1
int stu_query(string stu_number);


#endif
