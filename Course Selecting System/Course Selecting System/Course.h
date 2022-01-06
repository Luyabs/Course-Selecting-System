#pragma once
#include <iostream>

struct Course
{
	std::string id;
	std::string name;
	int	size;		//本课程当前选课人数
	int maxsize;	//本课程最大选课人数(容量)

	Course();							// 无参数的构造函数
	Course(string Id, string Name, int Size, int maxsize);	// 有参数的构造函数

	friend ostream& operator <<(ostream& fout, const Course& c);
	friend istream& operator >>(istream& fin, Course& c);
};

Course::Course():id(""), name(""), size(0), maxsize(0)
{
}

Course::Course(string Id, string Name, int Size, int Maxsize) :id(Id),name(Name),size(Size),maxsize(Maxsize)
{
}

ostream& operator<<(ostream& fout, const Course& c)
{
	fout << c.id << '\t'
		<< c.name << '\t' << c.size << '\t' << c.maxsize << endl;
	return fout;
}

istream& operator>>(istream& fin, Course& c)
{
	char str[100];
	fin.getline(str, 100, '\t'); c.id = str;
	fin.getline(str, 100, '\t'); c.name = str;
	fin.getline(str, 100, '\t'); c.size = atoi(str);
	fin.getline(str, 100); c.maxsize = atoi(str);
	return fin;
}
