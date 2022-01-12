#pragma once
#include "LinkList.h"
#include "CrossList.h"
#include "Student.h"
#include "Course.h"

class CSS							//Course Selecting System
{
protected:
	LinkList<Student> Students;		//总学生信息
	LinkList<Course> Courses;		//总课程信息
	CrossList<bool> Selection;		//选课关系矩阵--存储学生与课程关系的十字链表

public:
	//▲构造与析构函数
	CSS(bool read_only = 0, const char* stu = "stu.txt", const char* cou = "course.txt", const char* sel = "selection.txt");
	~CSS() {};

	//CSS
	void Load(const char* stu = "stu.txt", const char* cou = "course.txt", const char* sel = "selection.txt");	//为CSS整合Student Course Selction
	void Menu();							//为CSS整合功能菜单
	void Menu_Admin();						//选课系统管理员菜单
	void Menu_Student(const int& id);		//学生菜单
	void Save(const char* stu = "stu.txt", const char* cou = "course.txt", const char* sel = "selection.txt");	//为CSS整合Save

	//Student
	void StuSave(const char* filename = "stu.txt"); //保存学生名单到stu.txt的函数
	void StuReset();								//从stu.txt读取数据的函数
	Status AddStu();								//增加学生(管理员)
	Status DeleteStu();                             //减少学生(管理员)
	int FindStudent(const int& id) const;			//返回学生所在行数(从0数起) 将id从学号转行数的操作

	//Course & Course Choosing
	void CouSave(const char* filename = "course.txt");	//保存学生名单到course.txt的函数
	void CouReset();									//从course.txt读取数据的函数

	void EnlargeCou();							//课程扩容(管理员)
	void ReduceCou();
	Status FindCou_Admin() const;				//查询任意课程被选情况(管理员)
	void FindCou_Student(const int& id) const;	//查询学生自己选了什么课
	Status AddCou();							//增加课程(管理员)
	Status DeleteCou();							//删除课程(管理员)
	void ChooseCou(const int& id, Student& s);	//学生选课
	void UnChooseCou(const int& id, Student& s);//学生退课
	void TraverseCou() const;					//遍历课程

	//Selection
	void SelSave(const char* filename = "selection.txt");	//保存选择情况到selection.txt的函数
	void SelLoad();											//从selection.txt读取数据的函数
};
