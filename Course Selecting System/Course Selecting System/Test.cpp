#include "Course Selecting System.h"
using namespace std;

const char* datafile1 = "stu.txt";
const char* datafile2 = "course.txt";
const char* datafile3 = "selection.txt";

//!!! ��������switch-caseд�����ܲ˵�  �����ڴ򿪹��ܲ˵�ǰ��Ҫ�Զ����ļ��������Զ���������

int main()
{
	LinkList<Student> Students;
	Students.Load(datafile1);
	Students.Show();
	Students.Save(datafile1);
	system("Pause");
	LinkList<Course> Courses;
	Courses.Load(datafile2);
	Courses.Show();
	//cout << "���Ķ�Course Selecting System.h�ļ�" << endl;
	return 0;
}