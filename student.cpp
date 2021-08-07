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
	cout << "欢迎学生：" << this->m_name << "登入！" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        1、申请预约          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        2、查看我的预约      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        3、查看所有预约      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        4、取消预约          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        0、注销登录          |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "请选择您的操作！" << endl;
 }
void Student::applyorder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入您要申请预约的时间：" << endl;
	cout << "1、周一  2、周二  3、周三  4、周四  5、周五" << endl;
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
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	cout << "请输入申请预约的时间段！" << endl;
	cout << "1、上午   2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	cout << "请选择机房：" << endl;
	for (int i=0;i<vcom.size();i++)
	{
		cout << vcom[i].m_comid << " 号机房容量为：" << vcom[i].m_max << endl;
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
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	cout << "预约成功！审核中" << endl;
	ofstream ofs;
	ofs.open(orderfile, ios::app);
	ofs << "date：" << date << " " << "interval：" << interval << " " << "stuid：" << this->m_id << " " << "stuname：" << this->m_name << "roomid： " << room << " " << "status：" << 1<< endl;
	ofs.close();
	system("pause");
	system("cls");
}
void Student::showmyorder()
{
	Orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		if (this->m_id == atoi(of.m_orderdate[i]["stuid"].c_str()))
		{
			cout << "预约时间：周" << of.m_orderdate[i]["date"];
			cout << "时间段： " << (of.m_orderdate[i]["interval"]=="1"?"上午":"下午");
			cout << "机房号： " << of.m_orderdate[i]["roomid"];
			string status = "状态：";
			if (of.m_orderdate[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderdate[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderdate[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
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
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
		for (int i = 0; i < of.m_size; i++)
		{
			cout << i + 1 << "、";
			cout << "预约时间：周" << of.m_orderdate[i]["date"];
			cout << "时间段： " << (of.m_orderdate[i]["interval"] == "1" ? "上午" : "下午");
			cout << "学号：" << of.m_orderdate[i]["stuid"];
			cout << "姓名：" << of.m_orderdate[i]["stuname"];
			cout << "机房号： " << of.m_orderdate[i]["roomid"];
			string status = "状态：";
			if (of.m_orderdate[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderdate[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderdate[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
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
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	int index = 1; vector<int>v;
	for (int i = 0; i < of.m_size; i++)
	{
		if (this->m_id == atoi(of.m_orderdate[i]["stuid"].c_str()))
		{
			if (of.m_orderdate[i]["status"] == "1" || of.m_orderdate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++<<"、";
				cout << "预约时间：周" << of.m_orderdate[i]["date"];
				cout << "时间段： " << (of.m_orderdate[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房号： " << of.m_orderdate[i]["roomid"];
				string status = "状态：";
				if (of.m_orderdate[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderdate[i]["status"] == "2")
				{
					status += "预约成功";
				}
				else if (of.m_orderdate[i]["status"] == "-1")
				{
					status += "预约失败，审核未通过";
				}
				else
				{
					status += "预约已取消";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0表示返回" << endl;
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
				cout << "已取消预约！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}