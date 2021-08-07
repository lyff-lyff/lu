#include"student.h"
Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	ifstream ifs;
	ifs.open(computerfile, ios::in);
	Computerroom com;
	while (ifs >> com.m_comid&&ifs >> com.m_max)
	{
		vcom.push_back(com);
	}
	ifs.close();
}
void Student::openmenu()
{
	cout << "��ӭѧ����" << this->m_name << "���룡" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        1������ԤԼ          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        2���鿴�ҵ�ԤԼ      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        3���鿴����ԤԼ      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        4��ȡ��ԤԼ          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        0��ע����¼          |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
 }
void Student::applyorder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "��������Ҫ����ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ  2���ܶ�  3������  4������  5������" << endl;
	int date; int interval; int room;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������   2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
	cout << "��ѡ�������" << endl;
	for (int i=0;i<vcom.size();i++)
	{
		cout << vcom[i].m_comid << " �Ż�������Ϊ��" << vcom[i].m_max << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(orderfile, ios::app);
	ofs << "date��" << date << " " << "interval��" << interval << " " << "stuid��" << this->m_id << " " << "stuname��" << this->m_name << "roomid�� " << room << " " << "status��" << 1<< endl;
	ofs.close();
	system("pause");
	system("cls");
}
void Student::showmyorder()
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
		if (this->m_id == atoi(of.m_orderdate[i]["stuid"].c_str()))
		{
			cout << "ԤԼʱ�䣺��" << of.m_orderdate[i]["date"];
			cout << "ʱ��Σ� " << (of.m_orderdate[i]["interval"]=="1"?"����":"����");
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
	}
	system("pause");
	system("cls");
}
void Student::showallorder()
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
void Student::cancelorder()
{
	Orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	int index = 1; vector<int>v;
	for (int i = 0; i < of.m_size; i++)
	{
		if (this->m_id == atoi(of.m_orderdate[i]["stuid"].c_str()))
		{
			if (of.m_orderdate[i]["status"] == "1" || of.m_orderdate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++<<"��";
				cout << "ԤԼʱ�䣺��" << of.m_orderdate[i]["date"];
				cout << "ʱ��Σ� " << (of.m_orderdate[i]["interval"] == "1" ? "����" : "����");
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
		}
	}
	cout << "������ȡ���ļ�¼��0��ʾ����" << endl;
	int select;
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
				of.m_orderdate[v[select - 1]]["status"] = "0";
				of.updateorder();
				cout << "��ȡ��ԤԼ��" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}