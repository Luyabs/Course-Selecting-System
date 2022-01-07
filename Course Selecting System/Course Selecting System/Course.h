#pragma once
#include <iostream>
using namespace std;

struct Course
{
	string id;
	string name;
	int credit;		//本课程学分
	int maxsize;	//本课程最大选课人数(容量)

	Course();							// 无参数的构造函数
	Course(string Id, string Name, int Credit, int Maxsize);	// 有参数的构造函数
	string GetName() const; 			//返回课程名
	int GetCredit() const;
	int GetMaxsize() const;
	friend bool operator!=(Course a,Course b);
	friend ostream& operator <<(ostream& fout, const Course& c);
	friend istream& operator >>(istream& fin, Course& c);
};
