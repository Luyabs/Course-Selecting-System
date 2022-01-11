#include "Course Selecting System.h"

CSS::CSS(bool read_only, const char* stu, const char* cou, const char* sel)
{
	Load(stu, cou, sel);
	Menu();
	if (!read_only) Save(stu, cou, sel);
	else cout << endl << "请将read_only设置为False以保存" << endl;
}

void CSS::Load(const char* stu, const char* cou, const char* sel)
{
	Students.Load(stu);
	Courses.Load(cou);
	CrossList<bool> t(Students.GetLength(), Courses.GetLength());
	Selection = t;
	Selection.Load(sel);
	for (int i = 1; i <= Students.GetLength(); i++)			//构造十字链表
	{
		Student s;
		Students.GetElem(i, s);
		int n = 0;
		CrossNode<bool>* c;
		for (c = Selection.rowHead[i - 1]; c != NULL; c = c->right)
		{
			Course C;
			Courses.GetElem(c->triElem.col + 1, C);
			C.size++;
			Courses.SetElem(c->triElem.col + 1, C);
			n++;
		}
		s.num = n;
		Students.SetElem(i, s);
	}
}

void CSS::Menu()
{
	Student s;
	int id = -1;
	cout << "请输入学号：";
	while (id == -1)
	{
		cin >> id;					//没有学号会要求重输
		id = FindStudent(id);
	}
	cout << endl;
	if (id == 0)
		Menu_Admin();
	else
		Menu_Student(id);
}

void CSS::Menu_Admin()
{
	char c = '*';
	while (c != '0')
	{
		cout << endl << "1. 遍历课程.";
		cout << endl << "2. 遍历学生.";
		cout << endl << "3. 课程选课详情.";
		cout << endl << "4. 课程扩容.";
		cout << endl << "5. 删除课程.";
		cout << endl << "6. 新增课程.";
		cout << endl << "7. 增加学生.";
		cout << endl << "8. 移除学生.";
		cout << endl << "9. 查询学生选课情况";
		cout << endl << "0. 退出并保存";
		cout << endl << "选择功能(0~9):";
		cin >> c;
		switch (c) {
		case '1':
			TraverseCou();
			break;
		case '2':
			Students.Show();
			break;
		case '3':
			FindCou_Admin();
			break;
		case '4':
			EnlargeCou();
			break;
		case '5':
			DeleteCou();
			break;
		case '6':
			AddCou();
			break;
		case '7':
			AddStu();
			break;
		case '8':
			DeleteStu();
			break;
		case '9':
			int id;
			cout << "输入想要查找的学生学号: ";
			cin >> id;
			id = FindStudent(id);
			cout << endl;
			FindCou_Student(id);
			break;
		}
		cout << "========================================" << endl;
	}
}

void CSS::Menu_Student(const int& id)
{
	Student s;
	Students.GetElem(id, s);
	cout << "您好，" << s.name << endl;
	char c = '*';
	while (c != '0')
	{
		cout << endl << "1. 遍历课程.";
		cout << endl << "2. 查询已选课程.";
		cout << endl << "3. 选课.";
		cout << endl << "4. 删课.";
		cout << endl << "0. 退出并保存";
		cout << endl << "选择功能(0~4):";
		cin >> c;
		switch (c) {
		case '1':
			TraverseCou();
			break;
		case '2':
			FindCou_Student(id);
			break;
		case '3':
			ChooseCou(id, s);
			Students.SetElem(id, s);
			break;
		case '4':
			UnChooseCou(id, s);
			Students.SetElem(id, s);
			break;
		}
		cout << "========================================" << endl;
	}
}

void CSS::Save(const char* stu, const char* cou, const char* sel)
{
	StuSave(stu);
	CouSave(cou);
	SelSave(sel);
}

void CSS::StuSave(const char* filename)
{
	Students.Save(filename);
}

void CSS::StuReset()
{
	Students.Load("stu.txt");
}

void CSS::CouSave(const char* filename)
{
	Courses.Save(filename);
}

void CSS::CouReset()
{
	Courses.Load("course.txt");
}

void CSS::SelSave(const char* filename)
{
	Selection.Save(filename);
}

void CSS::SelLoad()
{
	Selection.Load("selection.txt");
}

Status CSS::AddStu()				//增加学生
{
	//cout << "这个函数没有改变num" << endl;
	int ID;
	string StuName;
	cout << "请输入新增学生的学号：";
	cin >> ID;
	for (int j = 1; j <= Students.GetLength(); j++)
	{
		Student s;
		if (s.id == ID)
		{
			cout << "该学号与原有学生冲突！" << endl;
			return FAIL;
		}
	}
	cout << "请输入新增学生的姓名：";
	cin >> StuName;
	Student stu(ID, StuName);
	Students.InsertElem(stu);
	Selection.AddRows();			//增加一行
	//cout<<Selection.GetRows()<<endl;
	//cout<<Selection.GetNum()<<endl;
	return SUCCESS;
}

Status CSS::DeleteStu()								//删除学生
{
	int StuId;
	cout << "请输入学生id：";
	cin >> StuId;
	for (int j = 1; j <= Students.GetLength(); j++)
	{
		Student S;
		Students.GetElem(j, S);
		if (S.id == StuId)
		{
			CrossNode<bool>* cn;
			for (cn = Selection.rowHead[j - 1]; cn != NULL; cn = cn->right)
			{
				Course C;
				Courses.GetElem(cn->triElem.col + 1, C);
				C.size--;
				Courses.SetElem(cn->triElem.col + 1, C);
			}
			Students.DeleteElem(j, S);					//删除 cou为课程信息
			Selection.DeleteRows(j-1);					//减一行
			cout << "学生已除名" << endl;
			return SUCCESS;
		}
		if (j == Students.GetLength())
		{
			cout << "未找到学号为" << StuId << "的学生" << endl;
			return NOT_PRESENT;
		}
	}
	return SUCCESS;
}

int CSS::FindStudent(const int &id)	const				//返回学生所在行数(从0数起)
{	
	if (id == 0)	return 0;
	Student s;
	for (int j = 1; j <= Students.GetLength(); j++)
	{
		Students.GetElem(j, s);
		if (s.id == id)
			return j;
	}
	cout << endl << "没有学号为" << id << "的学生" << endl;
	cout << "请重新输入你的学号: " << endl;
	return -1;
}

void CSS::EnlargeCou()
{
	string Courseid;
	cout << "请输入课程号：";
	cin >> Courseid;
	for (int j = 1; j <= Courses.GetLength(); j++)
	{
		Course C;
		Courses.GetElem(j, C);
		if (C.id == Courseid)
		{
			int ex = -1;
			while (ex < 0)
			{
				cout << "请输入要扩容的量(非负整数)：";
				cin >> ex;
			}
			C.maxsize += ex;
			Courses.SetElem(j, C);
			cout << "扩容成功" << endl;
			break;
		}
	}
}

Status CSS::FindCou_Admin() const						//查询课程被选情况
{
	string Courseid;
	cout << "请输入课程号：";
	cin >> Courseid;
	for (int j = 1; j <= Courses.GetLength(); j++)
	{
		Course C;
		Courses.GetElem(j, C);
		if (C.id == Courseid)
		{
			cout << std::left << setw(26) << "选课学生姓名：" << "学号：" << endl;
			CrossNode<bool>* sn;
			for (sn = Selection.colHead[j - 1]; sn != NULL; sn = sn->down)
			{
				Student stu;
				Students.GetElem(sn->triElem.row + 1, stu);
				cout << std::left << setw(30) << stu.name << stu.id << endl;
			}
			cout << "剩余名额：" << C.maxsize - C.size << endl;
			return SUCCESS;
		}
	}
	cout << "未找到课程号为" << Courseid << "的课程" << endl;
	return NOT_PRESENT;
}

void CSS::FindCou_Student(const int& id) const							//查询学生选了什么课
{
	CrossNode<bool>* cn;
	Student s;
	Students.GetElem(id, s);
	cout << "已选：" << s.num << "门，最多可选5门" << endl;
	cout << std::left << setw(15) << "课程号"
		<< setw(30) << "课程名" << setw(1) << "学分" << endl;
	for (cn = Selection.rowHead[id - 1]; cn != NULL; cn = cn->right)
	{
		Course C;
		Courses.GetElem(cn->triElem.col + 1, C);
		cout << std::left << setw(15) << C.id
			<< setw(30) << C.name << setw(1) << C.credits << endl;
	}
}

Status CSS::AddCou()
{
	string Courseid;
	string CouName;
	int CouCre;
	int CouMax;
	cout << "请输入新增课程号：";
	cin >> Courseid;
	cout << "请输入新增课程名：";
	cin >> CouName;
	cout << "请输入新增课程的学分：";
	cin >> CouCre;
	cout << "请输入新增课程的最大人数：";
	cin >> CouMax;
	for (int j = 1; j <= Courses.GetLength(); j++)
	{
		Course c;
		Courses.GetElem(j, c);
		if (c.id == Courseid || c.name == CouName)
		{
			cout << "与原有课程冲突！" << endl;
			return FAIL;
		}
	}
	Course cou(Courseid, CouName, CouCre, CouMax);
	Courses.InsertElem(cou);
	Selection.AddCols();			//增加一列
	//cout<<Selection.GetCols()<<endl;
	//cout<<Selection.GetNum()<<endl;
	return SUCCESS;
}

Status CSS::DeleteCou()
{
	string Courseid;
	cout << "请输入课程号：";
	cin >> Courseid;
	for (int j = 1; j <= Courses.GetLength(); j++)
	{
		Course C;
		Courses.GetElem(j, C);
		if (C.id == Courseid)
		{
			Courses.DeleteElem(j, C);					//删除 cou为课程信息
			Selection.DeleteCols(j - 1);					//减一列
			return SUCCESS;
		}
		if (j == Courses.GetLength())
		{
			cout << "未找到课程号为" << Courseid << "的课程" << endl;
			return NOT_PRESENT;
		}
	}
	return SUCCESS;
}


void CSS::ChooseCou(const int& id, Student& s)
{
	if (s.num >= 5)
		cout << "选课数目已达5门，不可再选！" << endl;
	else
	{
		cout << std::left << setw(15) << "课程号"
			<< setw(30) << "课程名" << setw(1) << "人数" << endl;
		for (int i = 1; i <= Courses.GetLength(); i++)
		{
			Course C;
			Courses.GetElem(i, C);
			cout << std::left << setw(15) << C.id
				<< setw(30) << C.name << setw(1) << C.size << '/' << C.maxsize << endl;
		}
		cout << "请输入课程号：";
		string Courseid;
		cin >> Courseid;
		for (int j = 1; j <= Courses.GetLength(); j++)
		{
			Course C;
			Courses.GetElem(j, C);
			if (C.id == Courseid)
			{
				if (C.size < C.maxsize)
				{
					bool already;
					Selection.GetElem(id - 1, j - 1, already);
					if (already)
					{
						cout << "你已选过这门课了" << endl;
						break;
					}
					Selection.SetElem(id - 1, j - 1, 1);
					s.num++;
					C.size++;
					Courses.SetElem(j, C);
					cout << "选课成功！" << endl;
					break;
				}
				else
				{
					cout << "课程容量已满！" << endl;
					break;
				}
			}
			if (j == Courses.GetLength())
				cout << "未找到课程号为" << Courseid << "的课程" << endl;
		}
	}
}

void CSS::UnChooseCou(const int& id, Student& s)
{
	if (s.num <= 0)
		cout << "没有选择任何课程，不可以进行退课操作！" << endl;
	else
	{
		cout << "请输入课程号：";
		string Courseid;
		cin >> Courseid;
		for (int j = 1; j <= Courses.GetLength(); j++)
		{
			Course C;
			Courses.GetElem(j, C);
			if (C.id == Courseid)
			{
				Selection.SetElem(id - 1, j - 1, 0);
				s.num--;
				C.size--;
				Courses.SetElem(j, C);
				cout << "退课成功" << endl;
				return;
			}
			if (j == Courses.GetLength())
				cout << "未找到课程号为" << Courseid << "的课程" << endl;
		}
	}
}

void CSS::TraverseCou() const
{
	cout << std::left << setw(15) << "课程号"
		<< setw(30) << "课程名" << setw(1) << "人数" << endl;
	for (int i = 1; i <= Courses.GetLength(); i++)
	{
		Course C;
		Courses.GetElem(i, C);
		cout << std::left << setw(15) << C.id
			<< setw(30) << C.name << setw(1) << C.size << '/' << C.maxsize << endl;
	}
}
