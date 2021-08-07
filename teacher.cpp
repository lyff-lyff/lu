#include"teacher.h"
Teacher::Teacher()
{

}
Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::openmenu()
{
	cout << "��ӭ��ʦ��" << this->m_name << "���룡" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        1���鿴����ԤԼ      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        2�����ԤԼ          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        3��ע����¼          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
 }
//�鿴����ԤԼ
void Teacher::showallorder()
{
	Orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼʱ�䣺��" << of.m_orderdate[i]["date"];
		cout << "ʱ��Σ� " << (of.m_orderdate[i]["interval"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << of.m_orderdate[i]["stuid"];
		cout << "������" << of.m_orderdate[i]["stuname"];
		cout << "�����ţ� " << of.m_orderdate[i]["roomid"];
		string status = "״̬��";
		if (of.m_orderdate[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderdate[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderdate[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ
void Teacher::validorder()
{
	Orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	int index = 1; vector<int>v;
	for (int i = 0; i < of.m_size; i++)
	{
			if (of.m_orderdate[i]["status"] == "1" )
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼʱ�䣺��" << of.m_orderdate[i]["date"];
				cout << "ʱ��Σ� " << (of.m_orderdate[i]["interval"] == "1" ? "����" : "����");
				cout << "�����ţ� " << of.m_orderdate[i]["roomid"];
				string status = "״̬������У�";
				cout << status << endl;
			}
	}
	cout << "��������˵�ԤԼ��¼��0��ʾ����" << endl;
	int select; int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1��ͨ��      2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderdate[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderdate[v[select - 1]]["status"] = "-1";
				}
				of.updateorder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}