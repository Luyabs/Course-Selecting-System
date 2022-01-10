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

	//CSS
	void Load();							//为CSS整合Student Course Selction
	void Menu();							//为CSS整合功能菜单
	void Menu_Admin();						//选课系统管理员菜单
	void Menu_Student(int id);				//学生菜单
	void Save();							//为CSS整合Save

	//Student
	void StuSave(const char* filename="stu.txt");  //保存学生名单到stu.txt的函数
	void StuReset();								 //从stu.txt读取数据的函数
	Status AddStu(int Id, string Name);				//增加学生
	Status DeleteStu();                             //减少
	
	//Course
	void CouSave(const char* filename = "course.txt");
	void CouReset();

	Status FindCou();							//查询课程被选情况
	Status AddCou();
	Status DeleteCou();
	
	//Selection
	void SelSave(const char* filename = "selection.txt");//保存选择情况到selection.txt的函数
	void SelLoad();//从selection.txt读取数据的函数
};
