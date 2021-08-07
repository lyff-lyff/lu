#pragma once
#include<iostream>
#include"identity.h"
#include"computerroom.h"
#include<string>
#include<vector>
#include<fstream>
#include"globalfile.h"
#include"orderfile.h"
using namespace std;
class Student :public Identity
{
public:
	Student();

	Student(int id,string name,string pwd);

	virtual void openmenu();

	void applyorder();

	void showmyorder();

	void showallorder();

	void cancelorder();

	int m_id;

	vector<Computerroom> vcom;
};