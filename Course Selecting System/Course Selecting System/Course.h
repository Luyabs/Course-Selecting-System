#pragma once
#include <iostream>

struct Course
{
	int id;
	std::string name;
	int	size;		//本课程当前选课人数
	int maxsize;	//本课程最大选课人数(容量)

	Course();							// 无参数的构造函数
	Course(int Id, int Name, int Size, int maxsize);	// 有参数的构造函数
};

//! 把上面两个成员函数实现一下