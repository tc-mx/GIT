/*
数据的插入--第一种：用insert函数插入pair数据
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string>(1, "student_one"));
    mapStudent.insert(pair<int, string>(2, "student_two"));
    mapStudent.insert(pair<int, string>(3, "student_three"));
    map<int, string>::iterator iter;

    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
        cout << iter->first << ' ' << iter->second << endl;
    return 0;
}
*/

/*
第二种：用insert函数插入value_type数据
#include <map>
#include <string>
#include <iostream>
    using namespace std;

int main()
{
    map<int, string> mapStudent;
    mapStudent.insert(map<int, string>::value_type(1, "student_one"));
    mapStudent.insert(map<int, string>::value_type(2, "student_two"));
    mapStudent.insert(map<int, string>::value_type(3, "student_three"));
    map<int, string>::iterator iter;

    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
        cout << iter->first << ' ' << iter->second << endl;
    return 0;
}
*/

#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    map<int, string> mapStudent;
    mapStudent[1] = "student_one";
    mapStudent[2] = "student_two";
    mapStudent[3] = "student_three";
    map<int, string>::iterator iter;

    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
        cout << iter->first << ' ' << iter->second << endl;

    return 0;
}