#pragma once
#include <iostream>

struct Course
{
	int id;
	std::string name;
	int	size;		//���γ̵�ǰѡ������
	int maxsize;	//���γ����ѡ������(����)

	Course();							// �޲����Ĺ��캯��
	Course(int Id, int Name, int Size, int maxsize);	// �в����Ĺ��캯��
};

//! ������������Ա����ʵ��һ��