#include "Course Selecting System.h"
using namespace std;

//!!! 在这里用switch-case写个功能菜单  考虑在打开功能菜单前需要自动用文件流输入自动加载数据

int main()
{
	LinkList<Student> Students;
	Students.Load(datafile1);
	Students.Show();
	system("Pause");
	LinkList<Course> Courses;
	Courses.Load(datafile2);
	Courses.Show();
	cout << "请阅读Course Selecting System.h文件" << endl;
	return 0;
}
