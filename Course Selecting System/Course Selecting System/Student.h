#pragma once
#include <iostream>
using namespace std;

struct Student
{
	int id;
	string name;
	int num;

	Student();						// 无参数的构造函数
	Student(int Id, string Name);		// 有参数的构造函数
	friend ostream& operator <<(ostream& fout, const Student& s);
	friend istream& operator >>(istream& fin, Student& s);
};

