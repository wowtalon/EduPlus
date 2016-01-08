#ifndef INCLUDED_H_INSERT_INFO
#define INCLUDED_H_INSERT_INFO

#include <string>

using namespace std;

// insert a record into the database, return 1 if succeed, else return 0
int insertInfo(string stu_number, string stu_name, string stu_birth, string stu_phone);

#endif
