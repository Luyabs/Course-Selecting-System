#pragma once
#include <iostream>
using namespace std;

struct Course
{
	string id;
	string name;
	int	credits;		//本课程当前选课人数
	int maxsize;	//本课程最大选课人数(容量)
	int size;

	Course();							// 无参数的构造函数
	Course(string Id, string Name, int Credits, int maxsize);	// 有参数的构造函数

	friend ostream& operator <<(ostream& fout, const Course& c);
	friend istream& operator >>(istream& fin, Course& c);
};
