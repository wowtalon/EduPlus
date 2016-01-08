#ifndef INCLUDED_H_QUERY
#define INCLUDED_H_QUERY

#include <string>

using namespace std;

// check that if there is a student whose student number is stu_number, if true return the line it exists, else return 0
int isexist(string stu_number);

// query a students' info where stu_nember == stu_number, return 0 if succeed, else return 1
int query_stu(string stu_number);


#endif
