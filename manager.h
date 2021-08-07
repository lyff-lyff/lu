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

	//���麯��
	virtual void openmenu();

	//����˺�
	void addperson();

	void showperson();

	void showcomputer();

	void cleanfile();

	//��ʼ������
	void initvector();

	//����ظ�
	bool checkrepet(int id, int type);

	//ѧ������
	vector<Student>vs;

	vector<Teacher>vt;

	//������Ϣ
	vector<Computerroom> vcom;


};
