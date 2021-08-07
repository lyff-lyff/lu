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
	cout << "机房数量为：" << vcom.size() << endl;
}
//纯虚函数
void Manager::openmenu()
{
	cout << "欢迎管理员："<<this->m_name<<"登入！" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        1、添加账号          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        2、查看账号          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        3、查看机房          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        4、清空预约          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|        0、注销登录          |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
	cout << "请选择您的操作！" << endl;
 }
//添加账号
void Manager::addperson()
{
	cout << "请选择添加账号类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加教师" << endl;
	string filename; string tip; string errortip;
	ofstream ofs; int select;
	cin >> select;
	if (select == 1)
	{
		filename = studentfile;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入！";
	}
	else
	{
		filename = teacherfile;
		tip = "请输入职工号：";
		errortip = "职工号重复，请重新输入！";
	}
	//追加方式写文件
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
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入登录密码：" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//更新接口，重新获取数据
	this->initvector();
}
void printfs(Student&s)
{
	cout << "学号：" << s.m_id << "姓名：" << s.m_name << "密码：" << s.m_pwd;
}
void printft(Teacher&t)
{
	cout << "职工号：" << t.m_empid << "姓名：" << t.m_name << "密码：" << t.m_pwd;
}
void Manager::showperson()
{
	cout << "请选择查看内容" << endl;
	cout << "1、查看所有学生    2、查看所有老师" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vs.begin(), vs.end(), printfs);
	}
	else
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vt.begin(), vt.end(), printft);
	}
	system("pause");
	system("cls");
}
void Manager::showcomputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<Computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "机房编号：" << it->m_comid << "机房最大容量：" << it->m_max;
	}
	system("pause");
	system("cls");
}
void Manager::cleanfile()
{
	ofstream ofs(orderfile, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}
//初始化容器
void Manager::initvector()
{
	vs.clear();
	vt.clear();
	ifstream ifs;
	ifs.open(studentfile, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件获取失败！" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vs.push_back(s);
	}
		cout <<"人数"<< vs.size();
		ifs.close();
	//老师
		ifs.open(teacherfile, ios::in);
		if (!ifs.is_open())
		{
			cout << "文件获取失败！" << endl;
			return;
		}
		Teacher t;
		while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
		{
			vt.push_back(t);
		}
		cout <<"人数"<< vt.size();
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