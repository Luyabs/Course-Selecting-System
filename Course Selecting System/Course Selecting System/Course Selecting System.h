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
	void Load(const char* stu= "stu.txt", const char* cou= "course.txt", const char* sel= "selection.txt");							//为CSS整合Student Course Selction
	void Menu();							//为CSS整合功能菜单
	void Menu_Admin();						//选课系统管理员菜单
	void Menu_Student(int id);				//学生菜单
	void Save(const char* stu = "stu.txt", const char* cou = "course.txt", const char* sel = "selection.txt");							//为CSS整合Save

	//Student
	void StuSave(const char* filename="stu.txt");  //保存学生名单到stu.txt的函数
	void StuReset();								 //从stu.txt读取数据的函数
	Status AddStu(int Id, string Name);				//增加学生
	Status DeleteStu();                             //减少
	int FindStudent(int id);						//返回学生所在行数(从0数起)
	
	//Course
	void CouSave(const char* filename = "course.txt");
	void CouReset();

	void EnlargeCou();							//课程扩容
	Status FindCou_Admin();						//查询任意课程被选情况
	void FindCou_Student(int id);				//查询学生自己选了什么课
	Status AddCou();							//增加课程
	Status DeleteCou();							//删除课程
	void ChooseCou(Student s);							//学生选课
	void TraverseCou();							//遍历课程
	
	//Selection
	void SelSave(const char* filename = "selection.txt");//保存选择情况到selection.txt的函数
	void SelLoad();//从selection.txt读取数据的函数
};
