#pragma once
#include<iostream>
#include"identity.h"
#include<string>
#include"orderfile.h"
#include<vector>
using namespace std; 
class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int empid, string name, string pwd);


	virtual void openmenu();

	//�鿴����ԤԼ
	void showallorder();

	//���ԤԼ
	void validorder();

	int m_empid;




};
