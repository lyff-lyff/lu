#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalfile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//����ѧ���Ӳ˵�
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
			cout << "ע���ɹ���" << endl;
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
			cout << "ע���ɹ���" << endl;
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
		   //cout << "����˺�" << endl;
		   man->addperson();
	   }
	   else if (select == 2)
	   {
		   //cout << "�鿴�˺�" << endl;
		   man->showperson();
	   }
	   else if (select == 3)
	   {
		   //cout << "�鿴����" << endl;
		   man->showcomputer();
	   }
	   else if (select == 4)
	   {
		   //cout << "���ԤԼ" << endl;
		   man->cleanfile();
	   }
	   else
	   {
		   delete manager;
		   cout << "ע���ɹ���" << endl;
		   system("pause");
		   system("cls");
		   return;
	   }
	}
}


void login(string filename, int type)
{
	//����ָ��  ָ���������
	Identity*person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//ѧ�����
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�����������û�����" << endl;
	cin >> name;
	cout << "�������������룺" << endl;
	cin >> pwd;
	if (type == 1)//��֤��Ϣ
	{
		int fid; string fname; string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����֤����ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
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
				cout << "��ʦ��֤����ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
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
				cout << "����Ա��֤����ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managermenu(person);
				return;
			}
		}
	}
	cout << "��֤����ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select;
	while (true)
	{
	cout << "*******************��ӭʹ�����ܻ���ԤԼϵͳ**********************" << endl;
	cout << endl << "                          �������������" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        1��ѧ  ��            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        2����  ʦ            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        3������Ա            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        0����  ��            |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "����������ѡ��" << endl;
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
		cout << "��ӭ�´�ʹ�ã�" << endl;
		system("pause");
		return 0;
		break;
	default:
		cout << "�����������������룡" << endl;
		system("pause");
		system("cls");
		break;
	  }
     }
system("pause");
return 0;
}
