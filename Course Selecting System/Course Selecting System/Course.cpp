#include "Course.h"

Course::Course() :id(""), name(""), credits(0), maxsize(0),size(0)
{
}

Course::Course(string Id, string Name, int Credits, int Maxsize) : id(Id), name(Name), credits(Credits), maxsize(Maxsize),size(0)
{
}

ostream& operator<<(ostream& fout, const Course& c)
{
	fout << c.id << '\t'
		<< c.name << '\t' << c.credits << '\t' << c.maxsize ;
	return fout;
}

istream& operator>>(istream& fin, Course& c)
{
	char str[100];
	fin.getline(str, 100, '\t'); c.id = str;
	fin.getline(str, 100, '\t'); c.name = str;
	fin.getline(str, 100, '\t'); c.credits = atoi(str);
	fin.getline(str, 100); c.maxsize = atoi(str);
	return fin;
}
