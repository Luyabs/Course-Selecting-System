#pragma once
#include "LinkList.h"
#include "CrossList.h"
#include "Student.h"
#include "Course.h"

class CSS							//Course Selecting System
{
protected:
	LinkList<Student> Students;		//ѧ����Ϣ+������Students.length
	LinkList<Course> Courses;			//�γ���Ϣ+������Courses.length
	CrossList<bool> Selection;			//ʮ������ ����:Students.length������Courses.length �����洢ĳѧ���Ƿ�ѡĳ�ſ���һ��Ϣ ��selection.txt

public:
	//����������������
	CSS();
	~CSS() {};

	//!!!����������麯��һ�㶯һ��������ԱStudents,Courses,Selection���ø�
	//!����Ѻ����ľ���ʵ��д��Course Selecting System.cpp��
	//�� �ļ���������������Բμ�CrossList�����������д�ĳ�Ա����
	
	
	//��Students
	//***��ѯĳѧ��ѡ������ĺ���
	//***ѧ��ѡ���˿�

	//***���Ӽ���ѧ��
	//......
	
	void StuSave(const char* filename="stu.txt");  //����ѧ��������stu.txt�ĺ���
	void StuReset();  //��stu.txt��ȡ���ݵĺ���

	//��Courses
	//***��ĳһ�ſ�maxsize(�γ�����)�ĺ���
	//***��ѯ�γ̵ĺ���
	
	//***����ɾ���γ̵ĺ���
	//......

	//***����γ̵�course.txt�ĺ���
	//***��course.txt��ȡ���ݵĺ���


	//��Selection
	//***��ѡ������ĺ���
	//......
	void SelSave(const char* filename = "selection.txt");//����ѡ�������selection.txt�ĺ���
	void SelLoad();//��selection.txt��ȡ���ݵĺ���
};
