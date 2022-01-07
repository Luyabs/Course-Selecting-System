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

Status CSS::FindStu()							//查询学生选课情况
{
	bool flag;
	int e;
	int id = 0;
	string name = "";
	char c = '#';
	cout<< "1.输入学号" << endl;
	cout<< "2.输入姓名" << endl;
	cout<< endl<< "请输入：";
	cin >> c;
	switch(c)
	{
	case '1':
		cout<< "输入学号：";
		cin >> id;
		break;
	case '2':
		cout<< "输入姓名：";
		cin >> name;
		break;
	default:
		return FAIL;
	}
	Student stu(id,name);
	Course cou;
	e = Students.LocateElem(stu);
	if(e == 0)
		return NOT_PRESENT;
	cout<< std::left << setw(26) << "所选课程："<< "学分："<< endl;
	for(int i = 0;i < Courses.GetLength();i++)
	{
		Selection.GetElem(e-1,i,flag);
		if(flag)
		{
			Courses.GetElem(i+1,cou);
			cout<< std::left << setw(30) << cou.GetName() <<  cou.GetCredit() << endl;
		}
	}
	return SUCCESS;
}

Status CSS::FindCou()							//查询课程被选情况
{
	bool flag;
	int e;
	string id = "";
	string name = "";
	char c = '#';
	cout<< "1.输入课程号" << endl;
	cout<< "2.输入课程名" << endl;
	cout<< endl<< "请输入：";
	cin >> c;
	switch(c)
	{
	case '1':
		cout<< "输入课程号：";
		cin >> id;
		break;
	case '2':
		cout<< "输入课程名：";
		cin >> name;
		break;
	default:
		return FAIL;
	}
	Course cou(id,name,0,0);
	Student stu;
	int num = 0;
	e = Courses.LocateElem(cou);
	if(e == 0)
		return NOT_PRESENT;
	cout<< std::left << setw(26) << "选课学生姓名："<< "学号："<< endl;
	for(int i = 0;i < Students.GetLength();i++)
	{
		Selection.GetElem(i,e-1,flag);
		if(flag)
		{
			num++;
			Students.GetElem(i+1,stu);
			cout<< std::left << setw(30) << stu.GetName() <<  stu.GetId() << endl;
		}
	}
	Courses.GetElem(e,cou);
	cout<< "剩余名额：" << cou.GetMaxsize() - num << endl;
	return SUCCESS;
}
