#pragma once
#include <iostream>
using namespace std;

struct Course
{
	string id;
	string name;
	int	size;		//���γ̵�ǰѡ������
	int maxsize;	//���γ����ѡ������(����)

	Course();							// �޲����Ĺ��캯��
	Course(string Id, string Name, int Size, int maxsize);	// �в����Ĺ��캯��

	friend ostream& operator <<(ostream& fout, const Course& c);
	friend istream& operator >>(istream& fin, Course& c);
};
