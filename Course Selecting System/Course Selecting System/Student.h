#pragma once
#include <iostream>

struct Student
{
	int id;
	std::string name;

	Student();						// 无参数的构造函数
	Student(int Id, string Name);		// 有参数的构造函数
	friend ostream& operator <<(ostream& fout, const Student& s);
	friend istream& operator >>(istream& fin, Student& s);

};
Student::Student():id(0),name("")
{
}

Student::Student(int Id, string Name):id(Id),name(Name)
{
}

ostream& operator<<(ostream& fout, const Student& s)
{
	fout << s.id << '\t' << s.name << endl;
	return fout;
}

istream& operator>>(istream& fin, Student& s)
{
	char str[80];
	fin.getline(str, 80, '\t'); s.id = atoi(str);
	fin.getline(str, 80); s.name = str;
	return fin;
}
