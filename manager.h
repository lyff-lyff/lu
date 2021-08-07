#pragma once
#include<iostream>
#include"identity.h"
#include<string>
#include<fstream>
#include"globalfile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerroom.h"
#include<algorithm>
using namespace std;
class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	//纯虚函数
	virtual void openmenu();

	//添加账号
	void addperson();

	void showperson();

	void showcomputer();

	void cleanfile();

	//初始化容器
	void initvector();

	//检测重复
	bool checkrepet(int id, int type);

	//学生容器
	vector<Student>vs;

	vector<Teacher>vt;

	//机房信息
	vector<Computerroom> vcom;


};
