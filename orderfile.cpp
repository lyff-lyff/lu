#include"orderfile.h"


Orderfile::Orderfile()
{
	ifstream ifs;
	ifs.open(orderfile, ios::in);
	string date;
	string interval;
	string stuid;
	string stuname;
	string roomid;
	string status;
	this->m_size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		string key; string value;
		map<string, string>m;
		int pos =date.find("£º");
		if (pos != -1)
		{
	      key = date.substr(0, pos);
		  value = date.substr(pos + 1, date.size() - pos - 1);
		  m.insert(make_pair(key, value));
		}
		 pos = interval.find("£º");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = stuid.find("£º");
		if (pos != -1)
		{
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = stuname.find("£º");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = roomid.find("£º");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = status.find("£º");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderdate.insert(make_pair(this->m_size, m));
		this->m_size++;

	}
	ifs.close();
}

void Orderfile::updateorder()
{
	if (this->m_size == 0)
	{
		return;
	}
	ofstream ofs(orderfile, ios::out|ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "date£º" << this->m_orderdate[i]["date"] << " ";
		ofs << "interval£º" << this->m_orderdate[i]["interval"] << " ";
		ofs << "stuid£º" << this->m_orderdate[i]["stuid"] << " ";
		ofs << "stuname£º" << this->m_orderdate[i]["stuname"] << " ";
		ofs << "roomid£º" << this->m_orderdate[i]["roomid"] << " ";
		ofs << "status£º" << this->m_orderdate[i]["status"] << endl;
	}
	ofs.close();
}