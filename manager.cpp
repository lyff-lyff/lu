#include"manager.h"

Manager::Manager()
{

}
Manager::Manager(string name, string pwd)
{
	this->m_name =name;
	this->m_pwd = pwd;
	this->initvector();
	ifstream ifs;
	ifs.open(computerfile, ios::in);
	Computerroom com;
	while (ifs>>com.m_comid&&ifs>>com.m_max)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "��������Ϊ��" << vcom.size() << endl;
}
//���麯��
void Manager::openmenu()
{
	cout << "��ӭ����Ա��"<<this->m_name<<"���룡" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        1������˺�          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        2���鿴�˺�          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        3���鿴����          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        4�����ԤԼ          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        0��ע����¼          |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
 }
//����˺�
void Manager::addperson()
{
	cout << "��ѡ������˺�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;
	string filename; string tip; string errortip;
	ofstream ofs; int select;
	cin >> select;
	if (select == 1)
	{
		filename = studentfile;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ������������룡";
	}
	else
	{
		filename = teacherfile;
		tip = "������ְ���ţ�";
		errortip = "ְ�����ظ������������룡";
	}
	//׷�ӷ�ʽд�ļ�
	ofs.open(filename, ios::out | ios::app);
	int id; string name; string pwd;
	cout << tip << endl;
	while (true)
	{	
		cin >> id;
		bool ret=checkrepet(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "�������¼���룺" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//���½ӿڣ����»�ȡ����
	this->initvector();
}
void printfs(Student&s)
{
	cout << "ѧ�ţ�" << s.m_id << "������" << s.m_name << "���룺" << s.m_pwd;
}
void printft(Teacher&t)
{
	cout << "ְ���ţ�" << t.m_empid << "������" << t.m_name << "���룺" << t.m_pwd;
}
void Manager::showperson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "1���鿴����ѧ��    2���鿴������ʦ" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vs.begin(), vs.end(), printfs);
	}
	else
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vt.begin(), vt.end(), printft);
	}
	system("pause");
	system("cls");
}
void Manager::showcomputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<Computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "������ţ�" << it->m_comid << "�������������" << it->m_max;
	}
	system("pause");
	system("cls");
}
void Manager::cleanfile()
{
	ofstream ofs(orderfile, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
//��ʼ������
void Manager::initvector()
{
	vs.clear();
	vt.clear();
	ifstream ifs;
	ifs.open(studentfile, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vs.push_back(s);
	}
		cout <<"����"<< vs.size();
		ifs.close();
	//��ʦ
		ifs.open(teacherfile, ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ȡʧ�ܣ�" << endl;
			return;
		}
		Teacher t;
		while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
		{
			vt.push_back(t);
		}
		cout <<"����"<< vt.size();
		ifs.close();
}
bool Manager::checkrepet(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}