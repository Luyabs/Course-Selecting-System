#include "Course.h"

Course::Course() :id(""), name(""), credit(0), maxsize(0)
{
}

Course::Course(string Id, string Name, int Credit, int Maxsize) : id(Id), name(Name), credit(Credit), maxsize(Maxsize)
{
}

string Course::GetName() const
{
	return name;
}

int Course::GetCredit() const
{
	return credit;
}

int Course::GetMaxsize() const
{
	return maxsize;
}

ostream& operator<<(ostream& fout, const Course& c)
{
	fout << c.id << '\t'
		<< c.name << '\t' << c.credit << '\t' << c.maxsize ;
	return fout;
}

istream& operator>>(istream& fin, Course& c)
{
	char str[100];
	fin.getline(str, 100, '\t'); c.id = str;
	fin.getline(str, 100, '\t'); c.name = str;
	fin.getline(str, 100, '\t'); c.credit = atoi(str);
	fin.getline(str, 100); c.maxsize = atoi(str);
	return fin;
}

bool operator!=(Course a,Course b)
{
	return !(a.id == b.id || a.name == b.name);
}
