#pragma once
#include <iostream>

struct Student
{
	int id;
	std::string name;

	Student();						// 无参数的构造函数
	Student(int Id, int Name);		// 有参数的构造函数

};

//! 把上面两个成员函数实现一下