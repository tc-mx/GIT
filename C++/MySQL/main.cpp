#include <iostream>
#include "MyDB.h"
using namespace std;

int main()
{
	MyDB db;
	db.initDB("localhost","root","23","test");
	db.exeSQL("select stu_num from student_info");
	return 0;
}
