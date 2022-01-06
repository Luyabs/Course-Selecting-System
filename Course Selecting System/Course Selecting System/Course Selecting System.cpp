#include "Course Selecting System.h"


CSS::CSS()
{
	Students.Load("stu.txt");
	Courses.Load("course.txt");
	Selection.Load("selection.txt");
}

void CSS::StuSave(const char* filename)
{
	Students.Save(filename);
}

void CSS::StuReset()
{
	Students.Load("stu.txt");
}

void CSS::SelSave(const char* filename)
{
	Selection.Save(filename);
}

void CSS::SelLoad()
{
	Selection.Load("selection.txt");
}