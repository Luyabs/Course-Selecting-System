#pragma once
#include "LinkList.h"
#include "CrossList.h"
#include "Student.h"
#include "Course.h"

class CSS							//Course Selecting System
{
protected:
	LinkList<Student> Students;		//学生信息+总数量Students.length
	LinkList<Course> Courses;			//课程信息+总数量Courses.length
	CrossList<bool> Selection;			//十字链表 行数:Students.length，列数Courses.length 用来存储某学生是否选某门课这一信息 见selection.txt

public:
	//▲构造与析构函数
	CSS();
	~CSS() {};

	//!!!以下三个板块函数一般动一个三个成员Students,Courses,Selection都得改
	//!！请把函数的具体实现写在Course Selecting System.cpp中
	//！ 文件流的输入输出可以参见CrossList中最后六个扩写的成员函数
	
	
	//①Students
	//***查询某学生选课情况的函数
	Status FindStu();
	//***学生选课退课

	//***增加减少学生
	Status AddStu(int Id, string Name);
	Status DeleteStu();
	//......
	
	void StuSave(const char* filename="stu.txt");  //保存学生名单到stu.txt的函数
	void StuReset();  //从stu.txt读取数据的函数

	//②Courses
	//***改某一门课maxsize(课程容量)的函数
	//***查询课程的函数
	Status FindCou();
	//***增加删除课程的函数
	Status AddCou(string Id, string Name, int Credit, int Maxsize = 45);
	Status DeleteCou();
	//......

	//***保存课程到course.txt的函数
	//***从course.txt读取数据的函数


	//③Selection
	//***改选择情况的函数
	//......
	void SelSave(const char* filename = "selection.txt");//保存选择情况到selection.txt的函数
	void SelLoad();//从selection.txt读取数据的函数
};
