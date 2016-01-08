#ifndef INCLUDED_H_INSERT_INFO
#define INCLUDED_H_INSERT_INFO

#include <string>

using namespace std;

// insert a record into the database, return 0 if succeed, else return 1
int insertInfo(string stu_number, string stu_name, string stu_birth, string stu_phone);

#endif
