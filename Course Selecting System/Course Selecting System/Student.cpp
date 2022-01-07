#include "Student.h"

Student::Student() :id(0), name("")
{
}

Student::Student(int Id, string Name) : id(Id), name(Name)
{
}

string Student::GetName() const
{
	return name;
}

int Student::GetId() const
{
	return id;
}

ostream& operator<<(ostream& fout, const Student& s)
{
	fout << s.id << '\t' << s.name ;
	return fout;
}

istream& operator>>(istream& fin, Student& s)
{
	char str[80];
	fin.getline(str, 80, '\t'); s.id = atoi(str);
	fin.getline(str, 80); s.name = str;
	return fin;
}

bool operator!=(Student a,Student b)
{
	return !(a.id == b.id || a.name == b.name);
}
