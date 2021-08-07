#pragma once
#include<iostream>
using namespace std;
#include"globalfile.h"
#include<fstream>
#include<map>
#include<string>
class Orderfile
{
public:
	Orderfile();

	void updateorder();

	int m_size;

	map<int, map<string,string>>m_orderdate;

};
