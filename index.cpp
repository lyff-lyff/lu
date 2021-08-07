#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalfile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入学生子菜单
void studentmenu(Identity*&student)
{
	while (true)
	{
		student->openmenu();
		Student*stu = (Student*)student;
		int select;
		cin >> select;
		if (select == 1)
		{
			stu->applyorder();
		}
		else if (select == 2)
		{
			stu->showmyorder();
		}
		else if (select == 3)
		{
			stu->showallorder();
		}
		else if (select == 4)
		{
			stu->cancelorder();
		}
		else
		{
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void teachermenu(Identity*&teacher)
{
	while (true)
	{
		teacher->openmenu();
		Teacher*tea = (Teacher*)teacher;
		int select;
		cin >> select;
		if (select == 1)
		{
			tea->showallorder();
		}
		if (select == 2)
		{
			tea->validorder();
		}
		else
		{
			delete teacher;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managermenu(Identity*&manager)
{
	while (true)
	{
       manager->openmenu();
	   Manager*man = (Manager*)manager;
	   int select;
	   cin >> select;
	   if (select == 1)
	   {
		   //cout << "添加账号" << endl;
		   man->addperson();
	   }
	   else if (select == 2)
	   {
		   //cout << "查看账号" << endl;
		   man->showperson();
	   }
	   else if (select == 3)
	   {
		   //cout << "查看机房" << endl;
		   man->showcomputer();
	   }
	   else if (select == 4)
	   {
		   //cout << "清空预约" << endl;
		   man->cleanfile();
	   }
	   else
	   {
		   delete manager;
		   cout << "注销成功！" << endl;
		   system("pause");
		   system("cls");
		   return;
	   }
	}
}


void login(string filename, int type)
{
	//父类指针  指向子类对象
	Identity*person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生身份
	{
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入您的用户名：" << endl;
	cin >> name;
	cout << "请输入您的密码：" << endl;
	cin >> pwd;
	if (type == 1)//验证信息
	{
		int fid; string fname; string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生验证登入成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单
				studentmenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fid; string fname; string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师验证登入成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师子菜单
				teachermenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		string fname; string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员验证登入成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员子菜单
				managermenu(person);
				return;
			}
		}
	}
	cout << "验证登入失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select;
	while (true)
	{
	cout << "*******************欢迎使用智能机房预约系统**********************" << endl;
	cout << endl << "                          请输入您的身份" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        1、学  生            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        2、教  师            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        3、管理员            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        0、退  出            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "请输入您的选择" << endl;
	cin >> select;
	  switch (select)
	  {
	case 1:
		login(studentfile, 1);
			break;
	case 2:
		login(teacherfile, 2);
		break;
	case 3:
		login(adminfile, 3);
		break;
	case 0:
		cout << "欢迎下次使用！" << endl;
		system("pause");
		return 0;
		break;
	default:
		cout << "输入有误，请重新输入！" << endl;
		system("pause");
		system("cls");
		break;
	  }
     }
system("pause");
return 0;
}
